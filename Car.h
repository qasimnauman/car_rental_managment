#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Vehicle.h"
using namespace std;

// Child Class Inherited by Vehicle...

class Car :public Vehicle
{
	protected:
		int NumDoor;
		int NumSeat;
	
	public:
		
		void setNumdoor(int nd);
		void setNumseat(int ns);
		int getNumdoor();
		int getNumseat();
};


void Car::setNumdoor(int nd)
{
	NumDoor=nd;
}

void Car::setNumseat(int ns)
{
	NumSeat=ns;
}

int Car::getNumseat()
{
	return NumSeat;
}

int Car::getNumdoor()
{
	return NumDoor;
}


#endif // CAR_H.