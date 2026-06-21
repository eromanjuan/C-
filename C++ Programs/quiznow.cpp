#include<iostream>
using namespace std;
int main(){
	string name;
	//cout<<name.length();
	cout<<"Enter your name :";
	getline(cin, name);
	
	for(int i = 0 ; i <=name.length() ;i++){
		cout<<name[i]<<endl;
	}
	
}

