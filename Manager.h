#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <fstream>
#include <string>
#include "SUV.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

class Manager {

public:
	void createVehicle();
	void displayvehicle();
	void removeVehicle(int ch, string& make);
	void UpdateVehicle(int ch,string& oldmake, string& newmodel, string& newnumberplate, float& newnil, int& newyear, int& new_num_d, int& new_num_s);
	string make, model, numberplate;
	int suvn = 0;
	int carn = 0;
	int truckn = 0;
	int year;
	float mil;
	void storeinfo()
	{
		cout << "Enter Make: ";
		getline(cin, make);
		cout << "Enter Model: ";
		getline(cin, model);
		cout << "Enter Year: ";
		cin >> year;
		cout << "Enter Mileage: ";
		cin >> mil;
		cout << "Enter Number Plate: ";
		cin >> numberplate;
	}
	void addSUV();
	void addCar();
	void addTruck();
};


void addvehiclemenu()
{
	cout << "Enter Category Of Vehicle you Want to add. \n";
	cout << " Press 1 for SUV \n";
	cout << "Press 2 for Car \n";
	cout << "Press 3 for Truck \n";
	cout << "Press 4 to Exit \n";
	cout << "Enter your choice : ";
}

void Manager::createVehicle()
{
	int choice=0;
	while (choice!=4)
	{
		addvehiclemenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin.ignore();
			addSUV();
			break;
		case 2:
			cin.ignore();
			addCar();
			break;
		case 3:
			cin.ignore();
			addTruck();
			break;
		case 4:
			cout << "Exiting....\n";
			break;

		default:
			cout << "Invalid Entry......\n";
			cout << "press any key to continue...\n";
			//getch();
			break;
		}
		return;

	}
}

void Manager::UpdateVehicle(int ch, string& oldmake, string& newmodel, string& newnumberplate, float& newmil, int& newyear, int& new_num_d, int& new_num_s)
{
	string file;
	if (ch==1)
	{
		file = "SUV in Inventory.txt";
	}
	else if (ch==2)
	{
		file = "Car in Inventory.txt";
	}
	else if (ch==3)
	{
		file = "Truck in Inventory.txt";
	}
	string temp = "temp.txt";
	ifstream read(file);
	ofstream write(temp);
	if (!read.is_open() || !write.is_open())
	{
		cout << "Failed to open file \n";
		return;
	}
	string line;
	int count=0;
	bool found = false;
	while (getline(read, line))
	{
		if(line== "\t Make is: "+oldmake)
		{
			found = true;
			write << "\t Make is: "<<oldmake << "\n";
			write << "\t Model is: " << newmodel << "\n";
			write << "\t Year is: " << newyear << "\n";
			write << "\t Number Plate: " << newnumberplate << "\n";
			write << "\t Mileage: " << newmil << "\n";
			if (ch == 1)
			{
				write << "\t Offroad Capcity: " << new_num_d << "\n";
				write << "\t Pasenger Capacity: " << new_num_s << "\n";
				count++;
				continue;
			}
			if (ch == 2)
			{
				write << "\t No of Doors: " << new_num_d << "\n";
				write << "\t No of Seats: " << new_num_s << "\n";
				count++;
				continue;
				
			}
			if (ch == 3)
			{
				write << "\t Cargo Capacity: " << new_num_d << "\n";
				write << "\t Towing Capacity: " << new_num_s << "\n";
				count++;
				continue;
			}
		}
		if (count>0 && count <=6)
			{
				count++;
				continue;
			}
			
		write << line <<endl;
	}
		

	read.close();
	write.close();
	
	if (!(found))
	{
		cout << "Vehicle not found \n";
		remove("temp.txt");
		return;
	}
	if (ch == 1)
	{	
		remove("SUV in Inventory.txt");
		rename("temp.txt", "SUV in Inventory.txt");
	}
	if (ch == 2)
	{
		remove("Car in Inventory.txt");
		rename("temp.txt", "Car in Inventory.txt");
	}
	if (ch == 3)
	{
		remove("Truck in Inventory.txt");
		rename("temp.txt", "Truck in Inventory.txt");
	}
	
	cout << "Vehicle Info updates successfully \n";
}			//End of Update Vehicle Function

void Manager::removeVehicle(int ch, string& make)
{
	string file;
	if (ch == 1)
	{
		file = "SUV in Inventory.txt";
	}
	else if (ch == 2)
	{
		file = "Car in Inventory.txt";
	}
	else if (ch == 3)
	{
		file = "Truck in Inventory.txt";
	}
	string temp = "temp.txt";
	ifstream read(file);
	ofstream write(temp);
	
	int count=0;
	string stored;
	bool found = false;
	
	if (!read.is_open() || !write.is_open())
	{
		cout << "Failed to open file. \n";
		return;
	}
	while (getline(read , stored))
	{
		
		if(stored== "\t Make is: "+make)
		{
			found = true;
			continue;
		}
		
		if (found && count<=6)
		{
			count++;
			continue;
		}
		
		write << stored <<endl;
		
	}
	read.close();
	write.close();
	if (ch==1)
	{
		remove("SUV in Inventory.txt");
		rename("temp.txt","SUV in Inventory.txt" );
		cout << "Removed Successfully" <<endl;
	}
	else if (ch==2)
	{
		remove("Car in Inventory.txt");
		rename("temp.txt","Car in Inventory.txt" );
		cout << "Removed Successfully" <<endl;
	}
	else if (ch==3)
	{
		remove("Truck in Inventory.txt");
		rename("temp.txt","Truck in Inventory.txt" );
		cout << "Removed Successfully" <<endl;
	}
	else {
		cout << "Invalid ..."<<endl;
	}
	
}

void Manager::displayvehicle()
{
	string car = "Car in Inventory.txt";
	string suv = "SUV in Inventory.txt";
	string truck = "Truck in Inventory.txt";
	ifstream Car(car);
	ifstream SUV(suv);
	ifstream Truck(truck);
	string line;
	cout << "\nDetails of Cars \n";
	if (!Car.is_open())
	{
		cout << "No information of cars found \n";
	}
	else
	{
		while (!Car.eof())
		{
			getline(Car, line);
			cout << line <<"\n";
		}
	}
	cout << "\nDeatails of SUV's \n";
	if (!SUV.is_open())
	{
		cout << "No information of SUV's found \n";
	}
	else
	{
		while (!SUV.eof())
		{
			getline(SUV, line);
			cout << line << "\n";
		}
	}
	cout << "\nDetails of Trucks \n";
	if (!Truck.is_open())
	{
		cout << "No information of trucks found \n";
	}
	else
	{
		while (!Truck.eof())
		{
			getline(Truck, line);
			cout << line << "\n";
		}
	}
}

void Manager::addSUV()
{
	SUV* suv = new SUV;
	storeinfo();
	cin.ignore();
	int offroadcap;
	cout << "Enter OffroadCapacity: ";
	cin >> offroadcap;
	cin.ignore();
	cout << "Enter Passenger Capacity: ";
	int passcap;
	cin >> passcap;
	suv->setMake(make);
	suv->setModel(model);
	suv->setMileage(mil);
	suv->setYear(year);
	suv->setNumberplate(numberplate);
	suv->setPassengerCap(passcap);
	suv->setOffroadCap(offroadcap);
	ofstream out;
	out.open("SUV in Inventory.txt", ios::app);
	{
		if (out.is_open())
		{
			out << "SUV NUM: " << suvn + 1 << " \n";
			suvn++;
			out<< "\t Make is: " <<   suv->getMake() << endl << "\t Model is: " << suv->getModel() << endl ;
			out << "\t Year is: " << suv->getYear() << "\n\t NumberPlate : " << suv->getNumberplate() << endl;
			out << "\t Mileage is: "<<suv->getMilage()<<endl;
			out << "\t Offroad Capacity: " << suv->getOffroadCap() << endl << "\t Passenger Capacity: " << suv->getPassengerCap() << endl;
			out.close();
		}

	}
	delete suv;

}

void Manager::addCar()
{
	Car* car = new Car;
	storeinfo();
	int numdoor;
	cout << "Enter Num of Doors: ";
	cin.ignore();
	cin >> numdoor;
	cout << "Enter Number of Seats: ";
	int numseat;
	cin >> numseat;
	car->setMake(make);
	car->setModel(model);
	car->setMileage(mil);
	car->setNumberplate(numberplate);
	car->setYear(year);
	car->setNumdoor(numdoor);
	car->setNumseat(numseat);
	ofstream out;
	out.open("Car in Inventory.txt", ios::app);
	{

		if (out.is_open())
		{
			out << "Car NUM: " << carn + 1 << " \n";
			carn++;
			out<< "\t Make is: " <<   car->getMake() << endl << "\t Model is: " << car->getModel() << endl ;
			out << "\t Year is: " << car->getYear() << "\n\t NumberPlate : " << car->getNumberplate() << endl;
			out << "\t Mileage is: "<<car->getMilage()<<endl;
			out << "\t Number of doors: " << car->getNumdoor() << endl << "\t Seats: " << car->getNumseat() << endl;
			out.close();
		}

	}
	delete car;
}

void Manager::addTruck()
{
	Truck* truck = new Truck;
	storeinfo();
	int cargocap, towcap;
	cout << "Enter Cargo Capacity : ";
	cin >> cargocap;
	cout << "Enter Towing Capacity : ";
	cin >> towcap;
	truck->setMake(make);
	truck->setYear(year);
	truck->setModel(model);
	truck->setMileage(mil);
	truck->setNumberplate(numberplate);
	truck->setCargoCap(cargocap);
	truck->setTowCap(towcap);
	ofstream out;
	out.open("Truck in Inventory.txt", ios::app);
	{
		if (out.is_open())
		{
			out << "Truck NUM: " << truckn + 1 << " \n";
			truckn++;
			out<< "\t Make is: " <<   truck->getMake() << endl << "\t Model is: " << truck->getModel() << endl ;
			out << "\t Year is: " << truck->getYear() << "\n\t NumberPlate : " << truck->getNumberplate() << endl;
			out << "\t Mileage is: "<<truck->getMilage()<<endl;
			out << "\t Cargo Capacity : " << truck->getCargoCap() << endl << "\t Towing Capacity : " << truck->getTowCap() << endl;
			out.close();
		}
	}
	delete truck;
}


#endif //MANAGER_H