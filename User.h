#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;
class User{
	protected:
		string username;
		string password;
	
	public:
		void setUsername(string uname);
		void setPassword(string pass);
		string getUsername();
		string getPassword(); 
};

void User::setUsername(string uname)
{
	this->username=uname;
}

void User::setPassword(string pass)
{
	this->password=pass;
}

string User::getPassword()
{
	return password;
}

string User::getUsername()
{
	return username;
}


#endif // USER_H