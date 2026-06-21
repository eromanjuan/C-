#include<iostream>
using namespace std;

int main(){
	string name;
	int i=0;
	cout<<"Name : ";
	getline(cin, name);
	
	do{
		cout<<name[i]<<endl;
		i++;
	}
	while(i<=name.length());
}
