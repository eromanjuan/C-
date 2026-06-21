#include<iostream>
using namespace std;
//Create a program that allows the user to enter 4 colors using an array and a loop, then display the last entered color as the first item in the list.
int main(){
	string color[4];
	cout<<"Enter 4 colors: \n";
	for(int i = 0 ; i<4 ; i++){
	cout<<i+1<<". ";
	cin>>color[i];
	}
	
	cout<<"\n\nThe colors you entered are :\n";
	for(int i = 3 ; i>=0 ; i--){
	cout<<i+1<<". ";
	cout<<color[i]<<endl;
	}
}
