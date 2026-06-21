#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	string str;
	cout<<"Enter your string : ";
	getline(cin , str);
	
	cout<<"\n\nYour original string : ";
	cout<<str;
	
	reverse(str.begin(), str.end()); 
	cout<<"\nYour string in reverse : ";
	cout<<str;
	
	reverse(str.begin(), str.end()); 	
	transform(str.begin(), str.end(), str.begin(),::toupper); 
	cout<<"\nYour string in upper case : ";
	cout<<str;	
		
	transform(str.begin(), str.end(), str.begin(),::tolower); 
	cout<<"\nYour string in lower case : ";
	cout<<str;
}
