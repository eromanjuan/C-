#include <iostream>
using namespace std;

int main()
{
	int num1, num2, sum, diff,prod, quo;
	cout<<"Enter the first integer :";
	cin>>num1;
	cout<<"Enter the second integer :";
	cin>>num2;
	sum = num1 + num2;
	diff = num1 - num2;
	prod = num1 * num2;
	quo = num1 / num2;
	cout<<"Sum + : "<<sum<<endl;
	cout<<"Diff - : "<<diff<<endl;
	cout<<"Prod *: "<<prod<<endl;
	cout<<"Quo /: "<<quo<<endl;
	return 0;	
	
}
