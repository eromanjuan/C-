#include<iostream>
using namespace std;
int main(){
	string txt;
	getline(cin, txt);
	
	for(int i ; i<= txt.length(); i++){
		cout<<txt[i]<<endl;
	}
}
