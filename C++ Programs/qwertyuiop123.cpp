#include<iostream>
#include<string>
using namespace std;

int main()
{
	string x;
	int i;
	cout<<"Enter a Name:";
	getline(cin, x);
	//cin>>x;
	cout<<x;
	cout<<"\nEnter the index: ";
	cin>>i;
	cout<<"Enter the char: ";
	cin>>x[i];
	cout<<x;
}

