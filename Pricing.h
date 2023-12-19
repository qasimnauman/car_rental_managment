#ifndef PRICING_H
#define PRICING_H
#include <iostream>
#include <string>
using namespace std;

class Pricing {
	protected:
		int RentalRate;
		int taxes;
		
	public:
		Pricing()
		{
			RentalRate=0;
			taxes=0;
		
		}
		void DisplayTotal(int Sdate, int EDate, int type);
};


void Pricing::DisplayTotal(int Sdate, int EDate, int type)
{
	if (type==1)
	{
		RentalRate=20;
	}
	else if(type==2)
	{
		RentalRate=40;
	}
	else if(type==3)
	{
		RentalRate=30;
	}
	int newRate= (EDate-Sdate)*RentalRate;
	taxes= (newRate/100)*25;
	RentalRate=newRate+taxes;
	cout << "Total Charges are: "<<RentalRate<<endl;
}

#endif // PRICIING_H