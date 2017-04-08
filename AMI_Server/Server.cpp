#include "Server.hpp"

Server::Server(int port, int max_clients){
	this->port =port;
	this->max_clients=max_clients;
	this->connected_clients=0;
	
	//Lets allocated the client sockets and addr. Also we should intialize them with a bunch of zeros
	this->client_sockets = new int [this->max_clients];
	this->clients_addr =  new sockaddr_in [this->max_clients];
	for(int i=0;i< this->max_clients;i++){
		this->client_sockets[i]=0;
		std::memset(&this->clients_addr[i],0,sizeof(sockaddr_in));
	}
	
	//Lets try to create a TCP socket for the server
	if((this->server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))<0)
		this->die("Error creating the TCP socket!!",2);
	
	//Yay, socket created. Now we will configure the addr
	std::memset(&this->server_addr,0,sizeof(sockaddr_in));
	this->server_addr.sin_family = AF_INET;						//IP
	this->server_addr.sin_addr.s_addr = htonl(INADDR_ANY);		//Any incoming addres
	this->server_addr.sin_port = htons(this->port);				//Setting the port;
	
	//Now, let's do our binding. Cross your fingers...
	if(bind(this->server_socket, (sockaddr *) &this->server_addr,sizeof(sockaddr_in))<0)
		this->die("Error binding to the requested port !!",3);
	
	//Good... I think that 5 pending connectons is a good number, so:
	if(listen(this->server_socket,5)<0)
		this->die("Error listening to the socket!!",4);
	
	//Things are looking good. We should go to the main loop now.
}

Server::~Server(){
	//Game over boys... Let's clean everything up!
	for(int i=0;i<this->max_clients;i++)
		if(this->client_sockets[i]>0)
			close(this->client_sockets[i]);
	
	delete[] this->client_sockets;
	delete[] this->clients_addr;
}

//

void Server::main_loop(){
	bool done=false;
	int max_sd=0;
	//Starting main loop
	while(!done){
		//Clering the socket set
		FD_ZERO(&this->readfds);
		
		//Adding the server socket to be selected
		FD_SET(this->server_socket,&this->readfds);
		max_sd = this->server_socket;			//Strange thing that selects needs
		
		//Now, let add all clients sockets to be selected
		for(int i=0;i<this->max_clients;i++)
			if(this->client_sockets[i]>0){
				FD_SET(this->client_sockets[i],&this->readfds);
				max_sd = (this->client_sockets[i]>max_sd)?this->client_sockets[i]:max_sd;
			}
		
		//Let start our select. Timeout will be null.
		if(select(max_sd+1,&readfds,NULL,NULL,NULL)<0 && errno!=EINTR)
			this->die("A select error!!",5);
		
		//Something happened in the server socket??
		if(FD_ISSET(this->server_socket,&this->readfds)){
			//Then, it is a new connection;
			int new_client_socket=0;
			sockaddr_in new_client_addr;
			int socklen=sizeof(sockaddr);
			
			if((new_client_socket = accept(this->server_socket,(sockaddr *)&new_client_addr,(socklen_t *)&socklen))<0){
				std::cout << new_client_socket << std::endl;
				this->die("Error accepting the client\n",6);
			}
			
			//Let's inform this new client
			std::cout << "We have a new client coming from IP: " << inet_ntoa(new_client_addr.sin_addr) << std::endl;
			
			//Let's check if we still have avlible slots
			if(this->connected_clients==this->max_clients){
				//Send something to the client
				std::cout << "Client disconnected because we are full\n" ;
			} else {
				//Now, we need to add this client to a free slot.
				for(int i=0;i<this->max_clients;i++)
					if(this->client_sockets[i]==0){
						this->client_sockets[i]=new_client_socket;
						std::memcpy(&this->clients_addr[i],&new_client_addr,sizeof(sockaddr_in));
						this->connected_clients++;
						
						//We sould probably inform everyone that this guy arrieved.
						this->broadcast("A new user connected!",this->client_sockets[i]);
						break;
					}
			}
		} else {
			//Then, it's must be a message from on of the clients
			for(int i=0;i<this->max_clients;i++)
				if(FD_ISSET(this->client_sockets[i],&this->readfds)){
					char buffer[BUFFSIZE];
					if(read(this->client_sockets[i],buffer,BUFFSIZE)==0){
						//Some traitor disconnected
						std::cout << "A cliente from " << inet_ntoa(this->clients_addr[i].sin_addr) << " disconnected\n";
						close(this->client_sockets[i]);
						this->client_sockets[i]=0;
						memset(&this->clients_addr[i],0,sizeof(sockaddr_in));
						this->connected_clients--;
					}
				} else {
					//Process the message
				}
		}
	}
}

void Server::die(std::string error, int error_n){
	// :(
	std::cout << error << std::endl;
	exit(error_n);
}


void Server::broadcast(std::string message){
	for(int i=0;i<this->max_clients;i++)
		if(this->client_sockets[i]>0)
			send(this->client_sockets[i],message.c_str(),message.size(),0);
}

void Server::broadcast(std::string message, int exception){
	for(int i=0;i<this->max_clients;i++)
		if(this->client_sockets[i]>0 && this->client_sockets[i]!=exception)
			send(this->client_sockets[i],message.c_str(),message.size(),0);
}

