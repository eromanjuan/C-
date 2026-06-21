#include <iostream>
using namespace std;

int main(){
	string name,course;
	int age;
	double allowance;
	char section;
	
	cout << "Enter your name: ";
	getline(cin,name);
	cout << "Enter your course: ";
	getline(cin,course);
	cout << "Enter your age: ";
	cin>>age;
	cout << "Enter your allowance: ";
	cin>>allowance;
	cout << "Enter your section: ";
	cin>>section;
	
	cout << "\n\n-----------------\n";
	cout << "Name: "<<name<<endl;
	cout << "Age: "<<age<<endl;
	cout << "Allowance: "<<allowance<<endl;
	cout << "Course: "<<course<<endl;
	cout << "Sction: "<<section<<endl;
	
	cout << "-----------------\n";
	return 0;
}
