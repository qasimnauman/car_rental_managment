#ifndef USERMAN_H
#define USERMAN_H
#include <iostream>
#include <fstream>
#include "User.h"

class Userman{
	protected:
		User u;
	public:
		void createUser();
		void removeUser();
		void UpdateUser(string& oldname,string& newUsername, string& newPassword);
		
		
};
void Userman::createUser()
{
	string username;
	string pass;
	cout << "Enter Username: ";
	cin >> username;
	cin.ignore();
	cout << "Enter Password: ";
	cin >>pass;
	u.setPassword(pass);
	u.setUsername(username);
	ofstream out;
	out.open("Admin.txt");
	if (out.is_open())
	{
		out <<u.getUsername()<<endl;
		out<<u.getPassword();
		out.close();
	}
}

void Userman::UpdateUser(string& oldname, string& newUsername,string& newPassword)
{
    string file = "Admin.txt";
    string temp= "temp.txt";

    ifstream read(file);
    ofstream write(temp);

    if (!read.is_open() || !write.is_open()) {
        cout << "Failed to open file." << endl;
        return;
    }

    string storedUsername;
    string storedPassword;
    bool found = false;

    while (getline(read, storedUsername)) {
        getline(read, storedPassword);

        if (storedUsername == oldname) {
            found = true;
            storedUsername = newUsername;
            storedPassword = newPassword;
            cout << "User information updated successfully." << endl;
        }
        write << storedUsername << endl;
        write << storedPassword << endl;
    }

    read.close();
    write.close();

    if (!found) {
        cout << "Username not found." << endl;
        remove("temp.txt");
        return;
    }
    remove("Admin.txt");
    rename("temp.txt", "Admin.txt");

    cout << "Update Sucessfully";
}

#endif // USERMAN_H