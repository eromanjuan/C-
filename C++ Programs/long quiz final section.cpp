#include <iostream>
using namespace std;

int main()
{
	int age = 18;
	int birthyear = 1995;
	double GcashBalance = 2000.50;
	double pangScatter = 1500.00;
	string name = "Roman";
	char section = 'A';
	
	cout<<"Name:"<<name<<endl;
	cout<<"Gcash Bal.:"<<GcashBalance<<endl;
	age = 2025 - birthyear;
	cout<<"Age:"<<age<<endl<<endl;
	
	GcashBalance = GcashBalance - pangScatter;
	
	cout<<"New Gcash Balance:"<<GcashBalance<<endl;
	
}


