#include "AMI.hpp"

AMI::AMI(){
	this->positiveVoltage=true;
}


char * AMI::fromAMI(char* ami,int n){
	char *packet = new char[n/2];
	std::memset(packet,0,n/2);
	int p2=7;
	for(int i=0;i<n;i++)
		for(int c=7;c>=0;c-=2,p2--){
			if(p2<0)
				p2=7;
			if(((ami[i]>>c)&0x1) == 0 && ((ami[i]>>(c-1))&0x1) == 0){
				packet[i/2]|=0<<p2;
			} else if(((ami[i]>>c)&0x1) == 0 && ((ami[i]>>(c-1))&0x1) == 1 && positiveVoltage){
				packet[i/2]|=1<<p2;
				positiveVoltage = false;
			} else if(((ami[i]>>c)&0x1) == 1 && ((ami[i]>>(c-1))&0x1) == 0 && !positiveVoltage){
				packet[i/2]|=1<<p2;
				positiveVoltage = true;
			} else
				return NULL;
		}
	return packet;
}

char * AMI::toAMI(char* packet, int n){
	char *ami = new char[n*2];
	std::memset(ami,0,n*2);
	for(int i=0;i<n;i++)
		for(int c=7,p1=i*2,p2=7;c>=0;c--,p2-=2){
			if(p2<0){
				p1++;
				p2=7;
			}
			if(((packet[i]>>c)&0x1) == 0){
				ami[p1]|=0<<(p2);
				ami[p1]|=0<<(p2-1);
			} else if(positiveVoltage){
				ami[p1]|=0<<(p2);
				ami[p1]|=1<<(p2-1);
				positiveVoltage=false;
			} else {
				ami[p1]|=1<<(p2);
				ami[p1]|=0<<(p2-1);
				positiveVoltage=true;
			}
		}
	return ami;
}


