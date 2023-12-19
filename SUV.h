#include <iostream>
#include "Vehicle.h"
#ifndef SUV_H
#define SUV_H
using namespace std;

//Child Class Inherited by Vehicle..

class SUV : public Vehicle {
	
	protected:
		int PassengerCap;
		int OffroadCap;
		
	public:
		SUV ()
		{
			PassengerCap=0;
			OffroadCap=0;
		}
		
		void setPassengerCap(int PC);
		void setOffroadCap(int orc);
		int getPassengerCap();
		int getOffroadCap();
		
};


void SUV::setPassengerCap(int PC)
{
	PassengerCap=PC;
}

void SUV::setOffroadCap(int orc)
{
	OffroadCap=orc;
}

int SUV::getPassengerCap()
{
	return PassengerCap;
}

int SUV::getOffroadCap()
{
	return OffroadCap;
}



#endif // SUV_H