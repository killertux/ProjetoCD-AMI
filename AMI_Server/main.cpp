#include <iostream>
#include <string>
#include "Server.hpp"

#include "AMI.hpp"

int main(int argc, char **argv) {
	Server *server;
	std::cout << "Server using the code line AMI.\nDeveloped by Bruno Clemente, Everton Santos Barreto Junior e Lucas Campos Tavano \n";
	if(argc!=3){
		std::cout << "Sintax error!! Use ami_server port max_clients\n\n";
		return 1;
	}
	
	server = new Server(std::stoi(argv[1]),std::stoi(argv[2]));
	server->main_loop();
	
    return 0;
}
