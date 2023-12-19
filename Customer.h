#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer {
public:
    string name;
    string address;
    string phone;

    Customer() {
        name = "";
        address = "";
        phone = "";
    }

    Customer(int i) {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Phone: ";
        getline(cin, phone);
    }

    string getName();
    string getAddress();
    string getPhone();
};

istream& operator>>(istream& in, Customer& cust);

string Customer::getName() {
    return name;
}

string Customer::getAddress() {
    return address;
}

string Customer::getPhone() {
    return phone;
}



istream& operator>>(istream& in, Customer& cust) {
    getline(in, cust.name);
    getline(in, cust.address);
    getline(in, cust.phone);
    return in;
}

#endif // CUSTOMER_H
