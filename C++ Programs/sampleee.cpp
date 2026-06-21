#include <iostream>
using namespace std;

int main(){
	int age ;
	double allowance ;
	char section ;
	string name, course;
	
	cout<<"Name : ";
	getline(cin,name);
	//cin>>name;
	cout<<"Course : ";
	cin>>course;
	cout<<"Age : ";
	cin>>age;
	cout<<"Allowance : ";
	cin>>allowance;
	cout<<"Section : ";
	cin>>section;
	
	cout<<"\n---------------------\n";
	cout<<"Name : "<<name<<endl;
	cout<<"Age : "<<age<<endl;
	cout<<"Course : "<<course<<endl;
	cout<<"Section : "<<section<<endl;
	cout<<"Allowance : "<<allowance<<endl;
	cout<<"---------------------\n";
	
	
	return 0;
	
}
