#include<iostream>
#include <stdlib.h>//this library is used because of the system clear screen
using namespace std;
//eto yung may goto function, if else function and sytem clear screen
int main(){
	int num1,num2;
	char op, sel;
	
	l:	//the goto function will go here
	
	cout<<"A. Addition\n";
	cout<<"B. Subtraction\n";
	cout<<"---------------\n";
	cout<<"Enter your choice : ";
	cin>>op;
	system("cls");//this will crear the entire screen console
	
	if(op=='a'|| op=='A'){ //if funtion to chect your input
		cout<<"--Addition--\n";
		cout<<"Enter two numbers\n";
		cin>>num1>>num2;
		cout<<"\nThe result is: "<<num1+num2<<"\n";
		j:
		cout<<"do you want to select another option? y/n : ";
		cin>>sel;
			if(sel=='y'){
				system("cls");
				goto l;
			}
			else if(sel=='n'){
				cout<<("\nThank you, Exiting...");
			}
			else{
				cout<<"Invalid Input...input must be y or n]\n\n";
				goto j;
			}
	}
	else if(op=='b'|| op=='B'){
		cout<<"--Subtraction--\n";
		cout<<"Enter two numbers\n";
		cin>>num1>>num2;
		cout<<"\nThe result is: "<<num1-num2<<"\n";
		n:
		cout<<"do you want to select another option? y/n : ";
		cin>>sel;
			if(sel=='y'){
				system("cls");
				goto l;
			}
			else if(sel=='n'){
				cout<<("Exiting");
			}
			else{
				cout<<"Invalid Input[input must be y or n]\n\n";
				goto n;
			}
	}
	else if(op=='c' || op=='C'){
		cout<<"Exiting... Thank you!";
		return 0;
	}
	else{
		system("cls");
		cout<<"Invalid Input[input must be A or B]\n\n";
		goto l;
	}
}

//roman juan eugeni i
