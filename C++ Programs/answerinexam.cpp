#include<iostream>
using namespace std;

int main(){
	string brand[4];
	cout<<"Enter 4 brands of smartphone:\n";
	for(int i = 0 ; i<=3; i++){
		cout<<i+1<<". ";
		cin>>brand[i];
	}
	
	cout<<"Brands:\n";
	for(int i = 3 ; i>=0; i--){
		cout<<i+1<<". "<<brand[i]<<endl;
	}
	
}
