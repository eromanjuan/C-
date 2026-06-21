#include<iostream>
using namespace std;

int main(){
	char opt;
	int a,b;	
	cout<<"\n[A] Addition";
	cout<<"\n[B] Subtraction";
	cout<<"\nEnter your choice : ";
	cin>>opt;
	
	if(opt=='a' || opt=='A'){
		cout<<"\n--Addition--\n";
		cout<<"\nEnter two numbers : \n";
		cin>>a>>b;
		cout<<"The result is : "<<a+b<<endl;
		
	}
	else if(opt=='b'|| opt=='B'){
		cout<<"\n--Subtraction--\n";
		cout<<"\nEnter two numbers : \n";
		cin>>a>>b;
		cout<<"The result is : "<<a-b<<endl;
		
	}
	else{
		cout<<"\nInvalid input!\n";
	}
}
