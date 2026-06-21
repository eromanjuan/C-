#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name;
	int i;
	cout<<"Enter your name : ";
	getline(cin, name);
	cout<<"Your name : "<<name;
	cout<<"\nEnter index number to change: ";
	cin>>i;
	cout<<"Enter the new character : ";
	cin>>name[i];
	cout<<"Your new name : "<<name;
}
