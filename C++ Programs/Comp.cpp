#include <iostream>
using namespace std;

int main() {
    int age;
    
    cout<<"Enter your age : ";
    cin>>age;
    if(age<=12){
    	cout<<"You are just a Kid!0";
		}
	else if(age<=17){
		cout<<"Sheesh you are a Teenager!";
	}
	else if(age<=25){
		cout<<"You are an adult";
	}
	else if(age<=40){
		cout<<"How's life as an adult? '";
	}
	else{
		cout<<"Deym are you an immortal";
	}
		


    return 0;
}

