#ifndef AMI_CLIENT_HPP
#define AMI_CLIENT_HPP

#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#include "BELMP.hpp"

class Client{
private:
	int client_socket;
	sockaddr_in client_addr;
	BELMP belmp;
public:
	Client(int client_socket,sockaddr_in *client_addr);
	~Client();
	
	//Gets and Sets
	int getClient_socket(){return this->client_socket;}
	sockaddr_in *getClient_addr(){return &this->client_addr;}
};

#endif
