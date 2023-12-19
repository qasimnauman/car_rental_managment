#include <iostream>
#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
using namespace std;

// Child class inherited by Vehicle...
class Truck : public Vehicle
{
	protected:
		int CargoCap;
		int TowCap;
		
	public:
		
		void setCargoCap (int cc);
		void setTowCap (int tc);
		int getCargoCap();
		int getTowCap();
};

void Truck::setCargoCap(int cc)
{
	CargoCap=cc;
}

void Truck::setTowCap(int tc)
{
	TowCap=tc;
}


int Truck::getCargoCap()
{
	return CargoCap;
}

int Truck::getTowCap()
{
	return TowCap;
}


#endif // TRUCK_H...

