#include<iostream>
using namespace std;

int main(){
	int num;
	
	cout<< "Enter a number :";
	cin>> num;
	
	if(num%2==0){
		cout <<"The number you entered is Even!\n";
	}
	else if(num%2==1){
		cout<< "The number you entered is Odd!\n";
	}
	else{
		cout<<"Invalid Input!";
	}
		
}
