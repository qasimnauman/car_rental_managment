#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Customer.h"
#include "SUV.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

class Reservation {
	private:
		int SDate;
		int EndD;
		Customer c;		// Composed of Customer
	public:
		Vehicle *v;
		Reservation(Vehicle &veh, Customer cus)
		{
			cout << "Enter Sdate: ";
			cin >> SDate;
			cout << "Enter End Date: ";
			cin >>EndD;
			v=&veh;
			this->c=cus;	
		}
		int getSDate();
		int getEndD();
		Customer getC();
};


int Reservation::getEndD()
{
	return EndD;
}

int Reservation::getSDate()
{
	return SDate;
}


Customer Reservation::getC(){
	return c;
}

#endif // RESERVATION_H