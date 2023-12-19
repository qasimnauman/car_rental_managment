#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Customer.h"
using namespace std;

class Customermanager
{
protected:
	Customer c;
public:
	void createcustomer();
	void updatecustomer(string& existingname,string& newname, string& newaddress, string& newphone);
};

void Customermanager::createcustomer()
{
	cout << "Enter the name, address and phone number of customer respectively \n";
	cin >> c;
	ofstream out;
	out.open("Customer.txt");
	if (out.is_open())
	{
		out << "Name: " << c.getName() << "\n";
		out << "Address: " << c.getAddress() << "\n";
		out << "Phone Number: " << c.getPhone() << "\n";
		out.close();
	}
}

void Customermanager::updatecustomer(string& existingname, string& newname, string& newaddress, string& newphone)
{
	string file = "Customer.txt";
	string temp = "temp.txt";

	ifstream read(file);
	ofstream write(temp);
	if (!read.is_open() || !write.is_open())
	{
		cout << "Failed to open file. \n";
		return;
	}

	string new_address;
	string new_name;
	string new_phone;
	bool found = false;

	while (read>>new_name>>new_address>>new_phone)
	{
		if (new_name==existingname)
		{
			new_name = newname;
			new_address = newaddress;
			new_phone = newphone;
			found = true;
		}
		write << "Name: " << new_name << "\n";
		write << "Address: " << new_address << "\n";
		write << "Phone: " << new_phone << "\n";
	}
	read.close();
	write.close();

	if (!found)
	{
		cout << "Customer not found \n";
		remove("temp.txt");
		return;
	}

	if (rename("temp.txt","Customer.txt") !=0)
	{
		cout << "Failed to over write existing file. \n";
		remove("temp.txt");
		return;
	}

	if (remove("Customer.txt")!=0)
	{
		cout << "Failed to remove the existing file. \n";
		remove("temp.txt");
		return;
	}

	cout << "Customer Information Updated successfully .\n";
}