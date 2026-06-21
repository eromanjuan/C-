#include <iostream>
using namespace std;

int main()
{
	int a,b;
	
	cout<<"enter the first number :";
	cin>> a;
	cout<<"enter the second number :";
	cin>> b;
	
	if(a > b)
	{
		cout<<a<<" is greater than "<<b;
	}
	else if (a == b)
	{
		cout<<a<<" equal to "<<b;
	}
	else
	{
		cout<<a<<" is less than "<<b;
	}
}
