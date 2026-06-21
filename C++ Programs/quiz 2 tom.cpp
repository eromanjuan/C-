#include<iostream>
using namespace std;
int main(){
	string name;
	cout<<"Enter yourname: ";
	getline(cin, name);
	cout<<name[name.length()-1];
}
