#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	string str;
	cout<<"Enter your string : ";
	getline(cin , str);
	
	cout<<"\ninputed string: \n";
	for( int i = 0 ; i<str.length() ; i++){
		cout<<"index ["<<i<<"] : "<<str[i]<<endl;
	}
	
	cout<<"\nreverse string: \n";
	reverse(str.begin(), str.end()); 
	for( int i = 0 ; i<str.length() ; i++){
		cout<<"index ["<<i<<"] : "<<str[i]<<endl;
	}
	
}
