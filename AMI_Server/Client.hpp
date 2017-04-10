#ifndef AMI_CLIENT_HPP
#define AMI_CLIENT_HPP

#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <string>

#include "BELMP.hpp"

class Client{
private:
	int client_socket;
	std::string nickname;
	sockaddr_in client_addr;
	BELMP *belmp;
public:
	Client(int client_socket,sockaddr_in *client_addr);
	~Client();
	
	//Gets and Sets
	int getClient_socket(){return this->client_socket;}
	sockaddr_in *getClient_addr(){return &this->client_addr;}
	std::string getNickname(){return this->nickname;}
	void setNickname(std::string nickname){this->nickname=nickname;}
	int getStatus(){return this->belmp->getStatus();}
	void setStatus(int status){this->belmp->setStatus(status);}
};

#endif
