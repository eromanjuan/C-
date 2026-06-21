#include <iostream>
using namespace std;

int main()
{
	string name, course;
	int age;
	double allowance;
	char section;
	
	cout<<"Enter your name : ";
	getline(cin, name);
	cout<<"Enter your course : ";
	cin>>course; //string
	cout<<"Enter your age : ";
	cin>>age;	//integer
	cout<<"Enter your allowance : ";
	cin>>allowance;	
	cout<<"Enter your section : ";
	cin>>section;
	
	cout<<"\n-----------------\n";
	cout<<"Name : "<<name<<endl;
	cout<<"Age : "<<age<<endl;
	cout<<"Allowance : "<<allowance<<endl;
	cout<<"Section : "<<section<<endl;
	cout<<"Course : "<<course<<endl;
	cout<<"-----------------\n";
	
	return 0;
}
