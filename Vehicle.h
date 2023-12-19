#include <iostream>
#include <string>
#ifndef VEHICLE_H
#define VEHICLE_H
using namespace std;

//Parent Class of SUV , CAR , TRUCK...

class Vehicle{
	protected:
		string make;
		string model;
		int year;
		string numberplate;
		float mileage;
		
	public:
	
		Vehicle()
		{
			make="";
			model="";
			year=0;
			numberplate="";
			mileage=0.0;
			
		}
		void Vehinput();
		void setMake(string m);
		void setModel(string mod);
		void setYear(int year);
		void setNumberplate(string np);
		void setMileage(float mil);
		string getMake();
		string getModel();
		int getYear();
		string getNumberplate();
		float getMilage();
				
};

void Vehicle::setMake(string m)
{
	this->make=m;
}

void Vehicle::setModel(string mod)
{
	this->model=mod;
}

void Vehicle::setYear(int year)
{
	this->year=year;
}

void Vehicle::setNumberplate(string np)
{
	this->numberplate=np;
}

void Vehicle::setMileage(float mil)
{
	this->mileage=mil;
}


string Vehicle::getMake()
{
	return make;
}

string Vehicle::getModel()
{
	return model;
}

int Vehicle::getYear()
{
	return year;
}

string Vehicle::getNumberplate()
{
	return numberplate;
}

float Vehicle::getMilage()
{
	return mileage;
}

#endif // VEHICLE_H
