#ifndef AMI_BELMP_HPP
#define AMI_BELMP_HPP

#include <stddef.h>
#include <cstring>
#include <iostream>		//Don't forget to remove this

#define PACKET_SIZE 256

#define STATUS_DISCONNECTED 0
#define STATUS_CONNECTION_REQUESTED 1
#define STATUS_CONNECTED 2

#define R_BROADCAST 0xff

#define F_REQUEST_CONNECTION 0x00
#define F_CONNECTION_ACCEPTED 0x01
#define F_CONNECTION_REJECTED_M_CLIENTS 0x02
#define F_CONNECTION_REJECTED_NICKNAME 0x03
#define F_CONNECTION_REJECTED_UNKNOWN 0x04
#define F_NEW_CLIENT 0x05
#define F_CLIENT_DISCONNECT 0x06
#define F_NEW_MESSAGE 0x07
#define F_ERROR_MESSAGE_SENDER 0x08
#define F_ERROR_MESSAGE_RECIEVER 0x09

struct _belmp_packet{
	char identifier[5];
	char function;
	char data[250];
};

class BELMP{
private:
	int status;
	bool client;
	
	static void setIdentifier(char identifier[5]);
public:
	BELMP(bool client);
	~BELMP();
	
	static bool check_packet(_belmp_packet *packet);
	
	static _belmp_packet *new_request_connection(char *nickname);
	static _belmp_packet *new_connection_accepted(char id, char max_clients);
	static _belmp_packet *new_error_message(char reason);
	static _belmp_packet *new_connection_rejected(char reason);
	static _belmp_packet *new_client(char id, char *nickname);
	static _belmp_packet *client_disconnect(char id);
	static _belmp_packet *new_message(char sender_id, char reciever_id,char *message);
	
	//Gets and Sets
	int getStatus(){return status;}
	void setStatus(int status){this->status=status;}
};

#endif
