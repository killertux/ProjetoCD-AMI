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

#define BUFFSIZE 1024

class Server {
private:
	int server_socket;
	int *client_sockets;
	int port, max_clients;
	int connected_clients;
	sockaddr_in server_addr;
	sockaddr_in *clients_addr;
	fd_set readfds;
	
	void die(std::string error, int error_n);				//In case of error
	void broadcast(std::string message);					//Send message for everyone connected
	void broadcast(std::string message,int exception);		//Send message for everyone connected with exception of 'exception'
	
public:
	Server(int port, int max_clients);
	~Server();
	void main_loop();										//Our main loop
	
	
};

#endif
