#include "Server.hpp"

Server::Server(int port, int max_clients){
	this->port =port;
	this->max_clients=max_clients;
	this->connected_clients=0;
	
	//Lets allocated the clients objects. Also we should intialize them with a bunch of zeros
	this->clients = new Client*[this->max_clients];
	for(int i=0;i<this->max_clients;i++)
		this->clients[i]=NULL;
	
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
		if(this->clients[i] != NULL)
			delete this->clients[i];
	
	delete[] this->clients;
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
		max_sd = this->server_socket;						//Strange thing that selects needs
		
		//Now, let add all clients sockets to be selected
		for(int i=0;i<this->max_clients;i++)
			if(this->clients[i]!=NULL){
				FD_SET(this->clients[i]->getClient_socket(),&this->readfds);
				max_sd = (this->clients[i]->getClient_socket())?this->clients[i]->getClient_socket():max_sd;
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
			
			//Let's check if we still have avalible slots
			if(this->connected_clients==this->max_clients){
				//Send something to the client
				std::cout << "Client disconnected because we are full\n" ;
			} else {
				//Now, we need to add this client to a free slot.
				for(int i=0;i<this->max_clients;i++)
					if(this->clients[i]==NULL){
						this->clients[i]=new Client(new_client_socket,&new_client_addr);
						this->connected_clients++;
						break;
					}
			}
		} else {
			//Then, it's must be a message from on of the clients
			for(int i=0;i<this->max_clients;i++)
				if(this->clients[i]!=NULL && FD_ISSET(this->clients[i]->getClient_socket(),&this->readfds)){
					char buffer[BUFFSIZE];
					if(read(this->clients[i]->getClient_socket(),buffer,BUFFSIZE)==0){
						//Some traitor disconnected
						_belmp_packet *packet;
						std::cout << "A client from " << inet_ntoa(this->clients[i]->getClient_addr()->sin_addr) << " disconnected\n";
						//Let's denouce him to everyone else!!
						packet = BELMP::client_disconnect(i);
						for(int c=0;c<this->max_clients;c++)
							if(this->clients[c]!=NULL && this->clients[c] != this->clients[i])
								write(this->clients[c]->getClient_socket(),packet,256);
						delete packet;
						
						FD_CLR(this->clients[i]->getClient_socket(),&this->readfds);
						delete this->clients[i];
						this->clients[i]=NULL;
						this->connected_clients--;
					} else {
						//Process the message
						if(BELMP::check_packet(buffer)){
							_belmp_packet *packet=(_belmp_packet*)&buffer;
							if(packet->function==F_REQUEST_CONNECTION && this->clients[i]->getStatus()==STATUS_DISCONNECTED){
								//Someone is newbie. Let's check if his Nickname is valid.
								bool valid=true;
								for(int c=0;c<this->max_clients;c++)
									if(this->clients[c]!=NULL && this->clients[c]->getNickname()==std::string(packet->data))
										valid=false;
								if(valid){
									//Lets send the response
									this->clients[i]->setNickname(packet->data);
									_belmp_packet *packet = BELMP::new_connection_accepted(i,this->max_clients);
									this->clients[i]->setStatus(STATUS_CONNECTED);
									write(this->clients[i]->getClient_socket(),packet,256);
									std::cout << "We accepted the new client with the nickname " << this->clients[i]->getNickname() <<std::endl;
									delete(packet);
									//We also should inform everyone else
									packet = BELMP::new_client(i,(char *)this->clients[i]->getNickname().c_str());
									this->broadcast(packet,this->clients[i]->getClient_socket());
									delete packet;
									//We should send to him all the connected clients;
									for(int c=0;c<this->max_clients;c++)
										if(this->clients[c]!=NULL && this->clients[c]!=this->clients[i]){
											packet = BELMP::new_client(c,(char *)this->clients[c]->getNickname().c_str());
											write(this->clients[i]->getClient_socket(),packet,256);
											delete packet;
										}
								} else {
									//Oh no. His nickname is already in use
									_belmp_packet *packet = BELMP::new_connection_rejected(F_CONNECTION_REJECTED_NICKNAME);
									write(this->clients[i]->getClient_socket(),packet,256);
									delete(packet);
									FD_CLR(this->clients[i]->getClient_socket(),&this->readfds);
									delete this->clients[i];
								}
							} else if(packet->function==F_NEW_MESSAGE && this->clients[i]->getStatus()==STATUS_CONNECTED){
								if(packet->data[0]!=i){
									//He is an impostor!!!!!
									std::cout << "Client " << inet_ntoa(this->clients[i]->getClient_addr()->sin_addr) << " tried to send a message from a differente client!\n";
									_belmp_packet *packet = BELMP::new_error_message(F_ERROR_MESSAGE_SENDER);
									write(this->clients[i]->getClient_socket(),packet,256);
									delete(packet);
								} else{
									if(packet->data[1]!=(char)R_BROADCAST){
										//Its a private message
										if(this->clients[packet->data[1]]==NULL){
											//He is trying to send the message to a ghost :O
											_belmp_packet *packet = BELMP::new_error_message(F_ERROR_MESSAGE_RECIEVER);
											write(this->clients[i]->getClient_socket(),packet,256);
											delete(packet);
										} else {
											//Let's send this message;
											write(this->clients[packet->data[1]]->getClient_socket(),packet,256);
										}
									} else {
										//He want's to broadcast
										this->broadcast(packet, this->clients[i]->getClient_socket());
									}
								}
							}
							
						} else {
							std::cout << "Client sent an unreadable message!\n";
						}
					}
				}
		}
	}
}

void Server::die(std::string error, int error_n){
	// :(
	std::cout << error << std::endl;
	exit(error_n);
}


void Server::broadcast(_belmp_packet *packet){
	for(int i=0;i<this->max_clients;i++)
		if(this->clients[i]!=NULL)
			write(this->clients[i]->getClient_socket(),packet,256);
}

void Server::broadcast(_belmp_packet *packet, int exception){
	for(int i=0;i<this->max_clients;i++)
		if(this->clients[i]!=NULL && this->clients[i]->getClient_socket()!=exception)
			write(this->clients[i]->getClient_socket(),packet,256);
}

