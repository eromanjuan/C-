#include<iostream>
using namespace std;
int main(){
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	if(num%2==0){
		cout<<num<<" The number you entered is even number!";
		}
	else if(num%2==1){
		cout<<num<<" The number you entered is odd number!";
	}
	else{
		cout<<"Invalid input!";
	}
	
}
