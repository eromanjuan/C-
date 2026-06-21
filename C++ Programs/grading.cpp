#include<iostream>
using namespace std;
//grading system zero based hahaha sample
int main(){
	int grade;
	
	cout<<"Enter your grade: ";
	cin>>grade;
	
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
		cout<<"Sorry you failed! :(";
	}
	else{
		cout<<"Invalid input ";
	}
}
//by Rom
