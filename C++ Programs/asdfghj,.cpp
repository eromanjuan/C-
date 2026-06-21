#include<iostream>
using namespace std;

int add(int c,int d){
	int c,d;
	cout<<c+d;
	
	return 0;
}
void sub(){
	int a=1,b=2;
	cout<<a-b;
}
void mul(){
	int a=1,b=2;
	cout<<a*b;
}
void div(){
	int a=1,b=2;
	cout<<a/b;
}

int main(){
	int a, b;
	add(a,b);
	cout<<"\n";
	sub();
	cout<<"\n";
	mul();
	cout<<"\n";
	div();
	
	return 0;	
}

