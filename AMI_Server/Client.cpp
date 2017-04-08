#include "Client.hpp"

Client::Client(int client_socket, sockaddr_in *client_addr){
	this->client_socket=client_socket;
	std::memcpy(&this->client_addr,client_addr,sizeof(sockaddr_in));
}


Client::~Client(){
	close(this->client_socket);
}


