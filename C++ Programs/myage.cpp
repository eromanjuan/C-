#include <iostream>
using namespace std;

int main()
{
	int birthyear, currentage;
	cout<<"Enter your birthyear: ";
	cin>>birthyear;
	
	currentage = 2025 - birthyear;
	cout<<"You are "<<currentage<<" years old!";
}
