#include "BELMP.hpp"

BELMP::BELMP(bool client){
	this->status=STATUS_DISCONNECTED;
	this->client=client;
}

BELMP::~BELMP(){
}

void BELMP::setIdentifier(char identifier[5]){
	char identifier_const[5]={'B','E','L','M','P'};
	std::memcpy(identifier,identifier_const,5);
}

_belmp_packet *BELMP::new_request_connection(char *nickname){
	_belmp_packet *packet = new _belmp_packet;
	BELMP::setIdentifier(packet->identifier);
	packet->function=F_REQUEST_CONNECTION;
	std::memset(packet->data,0,250);
	std::memcpy(packet->data,nickname,strlen(nickname));
	return packet;
}

_belmp_packet *BELMP::new_client(char id,char *nickname){
	_belmp_packet *packet = new _belmp_packet;
	BELMP::setIdentifier(packet->identifier);
	packet->function=F_NEW_CLIENT;
	std::memset(packet->data,0,250);
	packet->data[0]=id;
	std::memcpy(packet->data+1,nickname,strlen(nickname));
	return packet;
}

_belmp_packet *BELMP::client_disconnect(char id){
	_belmp_packet *packet = new _belmp_packet;
	BELMP::setIdentifier(packet->identifier);
	packet->function=F_CLIENT_DISCONNECT;
	packet->data[0]=id;
	std::memset(packet->data+1,0,250);
	return packet;
}

bool BELMP::check_packet(void* data){
	_belmp_packet *packet=(_belmp_packet*)data;
	if(packet->identifier[0]=='B' && packet->identifier[1]=='E' && packet->identifier[2]=='L' && 
		packet->identifier[3]=='M' && packet->identifier[4]=='P')
		return true;
	return false;
}

_belmp_packet *BELMP::new_connection_accepted(char id, char max_clients){
	_belmp_packet *packet=new _belmp_packet;
	BELMP::setIdentifier(packet->identifier);
	packet->function=F_CONNECTION_ACCEPTED;
	packet->data[0]=id;
	packet->data[1]=max_clients;
	std::memset(packet->data+2,0,248);
	return packet;
}

_belmp_packet * BELMP::new_connection_rejected(char reason){
	_belmp_packet *packet=new _belmp_packet;
	BELMP::setIdentifier(packet->identifier);
	packet->function=reason;
	std::memset(packet->data,0,250);
	return packet;
}

_belmp_packet *BELMP::new_message(char sender_id, char reciever_id,char *message){
	_belmp_packet *packet=new _belmp_packet;
	BELMP::setIdentifier(packet->identifier);
	packet->function=F_NEW_MESSAGE;
	packet->data[0]=sender_id;
	packet->data[1]=reciever_id;
	std::memset(packet->data+2,0,248);
	std::memcpy(packet->data+2,message,std::strlen(message));
	return packet;
}

_belmp_packet * BELMP::new_error_message(char reason){
	_belmp_packet *packet=new _belmp_packet;
	BELMP::setIdentifier(packet->identifier);
	packet->function=reason;
	std::memset(packet->data,0,250);
	return packet;
}



