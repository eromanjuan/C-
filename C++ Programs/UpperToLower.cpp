// C++ program to convert a string to uppercase 
#include <algorithm> // for using transform 
#include <cctype> // for using toupper 
#include <iostream> //alam niyo na to
#include <string> //saka to
using namespace std; 

int main() 
{ 

	string myStr;
	cout << "Input String is: " << endl; 
	getline(cin, myStr);
	//cin>>myStr;
	// using transform with toupper to convert mystr to 
	// uppercase 
	transform(myStr.begin(), myStr.end(), myStr.begin(),::tolower); 

	// printing string after conversion 
	cout << "String after conversion to uppercase: "
		<< myStr << endl; 

	return 0; 
}

