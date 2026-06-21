#include <iostream>
using namespace std;

int main()
{
	int birthyear, age;
	cout<<"Enter your birthyear : ";
	cin>>birthyear;
	
	age = 2025 - birthyear;
	
	cout<<"You are "<<age<<" year old!";
	return 0;
}
