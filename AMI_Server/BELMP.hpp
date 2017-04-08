#ifndef AMI_BELMP_HPP
#define AMI_BELMP_HPP

#define STATUS_DISCONNECTED 0
#define STATUS_CONNECTION_REQUESTED 1
#define STATUS_CONNECTED 2

#define F_REQUEST_CONNECTION 0x0
#define F_CONNECTION_ACCEPTED 0x1
#define F_CONNECTION_REJECTED_M_CLIENTS 0x2
#define F_CONNECTION_REJECTED_NICKNAME 0x3
#define F_CONNECTION_REJECTED_UNKNOWN 0x4
#define F_NEW_CLIENT 0x5
#define F_NEW_MESSAGE 0x6
#define F_ERROR_MESSAGE_SENDER 0x7
#define F_ERROR_MESSAGE_RECIEVER 0x8

struct _belmp_header{
	char identifier[5];
	char function;
	char data[250];
};

class BELMP{
private:
	_belmp_header header;
	int status;
	
public:
	BELMP();
	~BELMP();
	
	//Gets and Sets
	int getStatus(){return status;}
};

#endif
