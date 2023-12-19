#ifndef RESVMAN_H
#define RESVMAN_H
#include <iostream>
#include "Reservation.h"
#include "Customer.h"
#include "Vehicle.h"
#include "SUV.h"
#include "Car.h"
#include "Truck.h"
#include <fstream>
#include <ostream>
using namespace std;

class ReservationManager{
	 Reservation *res;
	public:
		ReservationManager()
		{
			int i;
		}
		void displayreservation();
		ReservationManager(Reservation &R);
		void CreateResv();
		void CancelResv(string name);
				
};
ReservationManager::ReservationManager(Reservation &R){
	res = &R;
}

void ReservationManager::CreateResv()
{
	int type;
	cout << "1: Car \n2: Truck\n3:SUV \nEnter Choice: ";
	cin >> type;
	string filetoread;
	if (type==1) // Car
	{
		filetoread="Car in Inventory.txt";
	}
	else if (type==2)
	{
		filetoread="Truck in Inventory.txt";
	}
	else if(type==3)
	{
		filetoread="SUV in Inventory.txt";
	}
	else 
	{
		cout << "invalid Input";
	}
	string filetowrite = "Reserved.txt";
	ofstream write;
	write.open(filetowrite, ios::app);
	ifstream read(filetoread);
	if (!write||!read)
	{
		cout << "Failed to open Files "<<endl;
		return;
	}
	string mak="\t Make is: "+res->v->getMake();
	string mod="\t Model is: "+res->v->getModel();
		string line;
		bool check=false;
		while (getline (read, line))
		{
			if (line==mak)
			{
				while (getline(read, line))
				{
					if (line==mod)
					check=true;
				}
						
			}
			if (check==true)
			{
				Pricing *p=new Pricing;
				write << "Name : "<<res->getC().getName() <<endl << "Phone: "<< res->getC().getPhone() <<endl << "Address: "
				<< res->getC().getAddress() << endl <<"Make: "<<res->v->getMake() <<endl <<"Model: "<<res->v->getModel()<<endl;
				p->DisplayTotal(res->getSDate(), res->getEndD(), type);
				cout << "RESERVATION SUCCESSFUL"<<endl;
				break;
			}	
		}
		read.close();
		write.close();
		if (check==false)
		{
			cout << "Car Not Found..";
			return;
		}
		
					
	
}

void ReservationManager::displayreservation()
{
	string file = "Reserved.txt";
	ifstream reserve(file);
	string line;
	int count = 1;
	if (!reserve.is_open())
	{
		cout << "No reservation information found \n";
	}
	else
	{
		cout << "Resrevation No. " << count << "\n";
		for (int i=0; i<4; i++)
		{
			getline(reserve, line);
			cout << line << "\n";
			count++;
		}
	}
	
}

void ReservationManager::CancelResv(string name)
{
    string file = "Reserved.txt";
    string temp = "temp.txt";
    ifstream read;
    read.open(file);

    ofstream write;
    write.open(temp);

    int count = 0;
    string stored;
    bool found = false;
    bool skip = false; // Flag to determine whether to skip writing lines

    if (!read || !write)
    {
        cout << "Failed to open file.\n";
        return;
    }

    while (getline(read, stored))
    {
        if (stored == "Name : " + name)
        {
            found = true;
            skip = true; // Skip writing lines from this point
            count++;
            continue;
        }

        if (skip && count <= 5)
        {
            count++;
            continue;
        }

        skip = false; // Stop skipping and start writing lines
        write << stored << endl;
    }

    read.close();
    write.close();

    if (found == false)
    {
        cout << "Reservation Not Found" << endl;
        return;
    }

    remove("Reserved.txt");
    rename("temp.txt", "Reserved.txt");
    cout << "Reservation Found" << endl;
    cout << "Removed Successfully" << endl;
}



#endif // RESVMAN_H