#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	string test;
	
	cout<<"enter a string : ";
	getline(cin, test);

	reverse(test.begin(), test.end());
	cout<<test;
}
