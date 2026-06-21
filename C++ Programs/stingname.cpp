#include <iostream>
using namespace std;

int main()
{
	string firstname, surname;
	cout<<"Firstname: ";
	getline(cin,firstname);
	cout<<"Surname: ";
	getline(cin,surname);
	
	cout<<firstname + surname;
	cout<<firstname.append(surname);
	return 0;
}
