#include<iostream>
using namespace std;
//Create a program that allows the user to enter 4 colors using an array and a loop, then display the last entered color as the first item in the list.
int main(){
	string brand[8];
	cout<<"Enter 4 brands of smart phone: \n";
	for(int i = 0 ; i<=3 ; i++){
	cout<<i+1<<". ";
	cin>>brand[i];
	}
	
	cout<<"\n\nThe 4 brands of smart phone you entered are :\n";
	for(int i = 3 ; i>=0 ; i--){
	cout<<i+1<<". ";
	cout<<brand[i]<<endl;
	}
}
