#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "Vehicle.h"
#include "SUV.H"
#include "Truck.h"
#include "Car.h"
#include "Reservation.h"
#include "Pricing.h"
#include "Customer.h"
#include "User.h"
#include "ResvMan.h"
#include "Manager.h"
#include "Userman.h"
#include "Customermanager.h"
#include "ResvMan.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void creatingnewuser();
void signin();
void updateuser();


bool Login(string& username, string& password)
{
	ifstream read("Admin.txt");

	if (read.is_open())
	{
		string storedUsername;
		string storedPassword;

		while (read >> storedUsername >> storedPassword)
		{
			if (username == storedUsername && password == storedPassword)
			{
				read.close();
				return true;
			}
		}

		read.close();
	}

	return false;
}

int main()
{
	int choice = 0;

	while (choice != 4)
	{
		Sleep(200);
		system("CLS");
		cout << "\n\t\t    ****** Welcome to Car Rental Shop ****** " << endl;
		cout << "\t\t      We provide the best services in town!" << endl;
		cout << "\t\tYou'll find exactly what you're looking for here! \n" << endl;
		cout << "\n\t\t\t\t **** MAIN MENU ****" << endl;
		cout << "Press 1 to Sign Up \n Press 2 to Sign in \n Press 3 to Update Profile \nPress 4 to Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			creatingnewuser();
			break;
		case 2:
			signin();
			break;
		case 3:
			updateuser();
			break;
		case 4:
			Sleep(50);
			cin.ignore();
			cout << "Exiting........\n\n";
			break;
		default:
			Sleep(500);
			cout << "Invalid option \n";
			cout << "Enter again \n";
			break;
		}
	} //End of while

	return 0;
}

void creatingnewuser()
{
	Userman* um = new Userman;
	um->createUser();
}

void signin()
{

	cout << "Login" << endl;
	string username, password;

	cout << "Enter username: ";
	cin >> username;

	cout << "Enter password: ";
	cin.ignore();
	cin >> password;

	if (Login(username, password))
	{
		system("CLS");
		Manager man;
		int choice, choice1;
		string ch = "y", chs = "y", chu = "y", chk = "y";
	jump:
		cout << "\nWelcome! " << username << endl;
		cout << "\nPress 1 to for Vehicle info \n";
		cout << "Press 2 for Reservation \n";
		cout << "Press 3 to go back to main menu \n";
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice > 3 || choice < 1)
		{
			cout << "Invalid Entry Enter again : ";
			cin >> choice;
		}
		while (!(choice == 3))
		{
			if (choice == 1)
			{
				cout << "\nPress 1 to add vehicles \n";
				cout << "Press 2 to update vehicles \n";
				cout << "Press 3 to remove vehicles \n";
				cout << "Press 4 to display stored vehicels \n";
				cout << "Press 5 to go to main menu \n";
				cin >> choice1;
				while (choice1>5 || choice<1)
				{
					cout << "Invalid entry, Enter again : ";
					cin >> choice1;
				}
				if (choice1 == 1)
				{
					ch = "y";
					while (ch == "y")
					{
						man.createVehicle();
						cout << "Do you want to add more vehicle?(y/n) : ";
						cin >> ch;
						if (ch == "n" || ch == "N") {
							break;
						}
					}
				}
				else if (choice1 == 2)
				{
					chu = "y";
					while (chu == "y")
					{
						string omake, model, numberplate;
						float mil;
						int year, ch, cap1, cap2;;
						cout << "Press 1 to update SUV.\nPress 2 to Update Car.\nPress 3 to update Truck.\n Enter choice : ";
						cin >> ch;
						cout << "Enter the old make : ";
						cin.ignore();
						getline(cin, omake);
						cout << "Enter the new model: ";
						getline(cin, model);
						cout << "Enter the new year : ";
						cin >> year;
						cout << "Enter the new number plate : ";
						cin.ignore();
						getline(cin, numberplate);
						cout << "Enter the mileage: ";
						cin >> mil;
						if (ch == 1)
						{
							cout << "Enter the Offroad Capacity: ";
							cin >> cap1;
							cout << "Enter the Pasenger capcity: ";
							cin >> cap2;
						}
						else if (ch == 2)
						{
							cout << "Enter the number of doors: ";
							cin >> cap1;
							cout << "Enter the number of seats: ";
							cin >> cap2;
						}
						else if (ch == 3)
						{
							cout << "Enter the cargo capacity: ";
							cin >> cap1;
							cout << "Enter the Towing capacity: ";
							cin >> cap2;
						}
						man.UpdateVehicle(ch, omake, model, numberplate, mil, year, cap1, cap2);
						cout << "\nDo you want to update any more vehicle?(y/n) : " ;
						cin >> chu;
						if (chu == "n" || chu == "N") {
							break;
						}
					}
				}
				else if (choice1 == 3)
				{
					string omake;
					int ch;
					cout << "Press 1 to remove SUV.\nPress 2 to remove Car.\nPress 3 to remove Truck.\n Enter choice : ";
					cin >> ch;
					cout << "Enter the  make : ";
					cin.ignore();
					getline(cin, omake);
					string omodel;
					man.removeVehicle(ch, omake);
				}
				else if (choice1 == 4)
				{
					man.displayvehicle();
				}
				else if (choice1 == 5)
				{
					goto jump;
				}
			}
			else if (choice == 2)
			{
				int ch=0;
				while (!(ch == 4))
				{
					cout << "\nPress 1 for Reservation \n Press 2 for Cancel Reservation ";
					cout<<"\n Press 3 to Display Reservations \nPress 4 to goto previous menu " << endl;
					cin >> ch;
					while (ch > 4 || ch < 1)
					{
						cout << "Invalid Entry Enter again : ";
						cin >> ch;
					}
					if (ch == 1)
					{
						chk == "y";
						while (chk == "y")
						{
							Vehicle vehicle;
							Customer cus(1);
							string mk, mod;
							cout << "Enter Make: ";
							cin >> mk;
							cout << "Enter Model: ";
							cin >> mod;
							vehicle.setMake(mk);
							vehicle.setModel(mod);

							Reservation r(vehicle, cus);
							ReservationManager rm(r);
							rm.CreateResv();
							cout << "\nDo you want to add more reserations (y/n) : ";
							cin >> chk;
							if (chk == "n" || chk == "N")
							{
								break;
							}
						}
					}
					else if (ch == 2)
					{
						chk = "y";
						while (chk == "y" || chk == "Y")
						{
							string name;
							cout << "Enter Name: ";
							cin.ignore();
							getline(cin, name);
							ReservationManager R;
							R.CancelResv(name);
							cout << "\nWant to cancel more reservations(y/n) : ";
							cin >> chk;
							if (chk == "n" || chk == "N")
							{
								break;
							}
						}
					}
					else if (ch==3)
					{
						ReservationManager R;
						R.displayreservation();
					}
					else if (ch == 4)
					{
						goto jump;
					}
				}
				
			}
		}
	}
	else
	{
		cout << "Invalid username or password." << endl;
	}
}

void updateuser()
{
	string newusername;
	string pass;
	Userman* u = new Userman;
	cout << "Enter Username you want to Changer: ";
	string name;
	cin.ignore();
	getline(cin, name);
	//cin.ignore();

	cout << "Enter New Username: ";
	getline(cin, newusername);
	cout << "Enter New Password: ";
	getline(cin, pass);

	u->UpdateUser(name, newusername, pass);
}