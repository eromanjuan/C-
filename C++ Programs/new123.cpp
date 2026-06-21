#include <iostream> 
using namespace std;

int main()
{
	int num1, num2, num3, num4, result, ave;
	cout<<"Enter your prelim grade: ";
	cin>>num1;
	cout<<"Enter your midterm grade: ";
	cin>>num2;
	cout<<"Enter your semi-final grade: ";
	cin>>num3;
	cout<<"Enter your final grade: ";
	cin>>num4;
	
	result= num1 + num2 + num3 + num4 ;
	ave = result/4;
	cout<<"The sum is: "<<ave;
	return 0;
}
