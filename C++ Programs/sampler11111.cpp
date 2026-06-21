#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cout<<"Enter the first number: ";
	cin>>a;
	cout<<"Enter the second number: ";
	cin>>b;
	
	if(a>b)
	{
		cout<<a<<" is greater than "<<b;
	}
	else if(a<b)
	{
		cout<<a<<" is less than "<<b;
	}
	else if(a==b)
	{
		cout<<a<<" is equal to "<<b;
	}
	else
	{
		cout<<"Invalid Input!";
	}
	
}
