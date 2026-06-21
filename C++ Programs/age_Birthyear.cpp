#include<iostream>
using namespace std;

int main(){
	int yourAge, byear;
	int currYear = 2025;
	
	cout<<"Enter your birth year : ";
	cin>>byear;
	
	yourAge  = currYear - byear;
	
	cout<<"Your current age is "<<yourAge<<" years old";	
}
