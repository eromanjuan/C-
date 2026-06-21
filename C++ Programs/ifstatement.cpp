#include <iostream>
using namespace std;

int main()
{
	int a;
	cout<<"Enter any number :";
	cin>>a;
	
	if(a%2==0)
	{
		cout<<"The number you have entered is a even number!";
	}
	else if(a%2==1)
	{
		cout<<"The number you have entered is a odd number!";
	}
	else
	{
		cout << "Invalid input!";
	}
}
