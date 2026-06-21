#include<iostream> 
//simple calculator add and minus only 
using namespace std;

int main(){
	char opt;
	int a,b;
	cout<<"\nA. Add\n";
	cout<<"B. Sub\n\n";
	cout<<"Enter your choice :";
	cin>>opt;
	
	if(opt=='a' || opt=='A' ) {
		cout<<"--Add--";
		cout<<"\nEnter two numbers\n";
		cin>>a>>b;
		cout<<"The result is: "<<a+b<<"\n";
	}
	else if(opt=='b' || opt=='B'){
		
		cout<<"--Sub--";
		cout<<"\nEnter two numbers\n";
		cin>>a>>b;
		cout<<"The result is: "<<a-b<<"\n";
	}
	
	else{
		cout<<"Invalid Input";
	}
}
