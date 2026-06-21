#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	float g1,g2,g3,g4,p,m,s,f;
	int sel;
	l:
	cout<<"Enter your Prelim Grade : ";
	cin>>g1;
	cout<<"Enter your Midterm Grade : ";
	cin>>g2;
	cout<<"Enter your Semi Final Grade : ";
	cin>>g3;
	cout<<"Enter your Final Grade : ";
	cin>>g4;
	
	p=g1*0.2;
	m=g2*0.3;
	s=g3*0.2;
	f=g4*0.3;
	cout<<"\n";
	cout<<"[20%] Prelim : "<<p<<endl;
	cout<<"[30%] Midterm : "<<m<<endl;
	cout<<"[20%] Semis : "<<s<<endl;
	cout<<"[30%] Final : "<<f<<endl;
	float grade= p + m + s + f;
	cout<<"\n";
	cout<<"grade total : "<<grade;
	cout<<"\n";
	cout<<"\n";
	
	if(grade>=96 && grade<=100){ //condition using comparison and logical operator
		cout<<"your grade is 1.00 ";
	}
	else if(grade>=91.5 && grade<=95.9){
		cout<<"your grade is 1.25";
	}
	else if(grade>=87 && grade<=91.4){
		cout<<"your grade is 1.5";
	}
	else if(grade>=82.5 && grade<=86.9){
		cout<<"your grade is 1.75";
	}
	else if(grade>=78 && grade<=82.4){
		cout<<"your grade is 2.00";
	}
	else if(grade>=73.5 && grade<=77.9){
		cout<<"your grade is 2.25";
	}
	else if(grade>=69 && grade<=73.4){
		cout<<"your grade is 2.5 ";
	}
	else if(grade>=64.5 && grade<=68.9){
		cout<<"your grade is 2.75";
	}
	else if(grade>=60 && grade<=64.4){
		cout<<"your grade is 3.00";
	}
	else if(grade < 60){
		cout<<"Sorry you failed! :(\n";
	}
	else{
		cout<<"Invalid input \n";
	}

}
