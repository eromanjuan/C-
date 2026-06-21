#include<iostream>
#include <algorithm> 
/*Write a program that will reverse, and convert your 
 input into upper case and 
 add some special character as style*/
using namespace std;
//Create a program that takes a string input, reverses it, converts it to uppercase, and adds special characters for styling.
int main(){
	string text;
	cout<<"Input your string: ";
	getline(cin , text);
	cout<<"\n\nYour Output String: \n\n";
	reverse(text.begin(), text.end()); 
	transform(text.begin(), text.end(), text.begin(),::tolower); 
	
	for(int i = 0 ; i < text.length() ; i++){
		cout<<"("<<text[i]<<")"<<"\t";
	}
	
}
