#ifndef AMI_AMI_HPP
#define AMI_AMI_HPP

#include <bitset>
#include <cstring>

#include "BELMP.hpp"

/*	Voltage Map:
 * Positive Voltage = 10
 * Negative Voltage = 01
 * Null Voltage = 00
 */


class AMI{
private:
	bool positiveVoltage;
	
public:
	AMI();
	char *toAMI(char *packet,int n);
	char *fromAMI(char *ami, int n);
};

#endif
