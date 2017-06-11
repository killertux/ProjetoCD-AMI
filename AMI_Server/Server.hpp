#ifndef AMI_SERVER_HPP
#define AMI_SERVER_HPP

#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <cstring>

#include "Client.hpp"
#include "BELMP.hpp"

#define DEBUG true

#define BUFFSIZE 1024

class Server {
private:
	int server_socket;
	Client **clients;
	int port, max_clients;
	int connected_clients;
	sockaddr_in server_addr;
	fd_set readfds;
	
	void die(std::string error, int error_n);				//In case of error
	void broadcast(_belmp_packet *packet);					//Send message for everyone connected
	void broadcast(_belmp_packet *packet,int exception);		//Send message for everyone connected with exception of 'exception'
	
public:
	Server(int port, int max_clients);
	~Server();
	void main_loop();										//Our main loop
	
	
};

#endif
