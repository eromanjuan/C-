#include<iostream>
using namespace std;
int main(){
	float num1, num2, result;
	int choice;
	l:
	cout<<"------------------"<<endl;
	cout<<"[1] Addition"<<endl;
	cout<<"[2] Subtraction"<<endl;
	cout<<"[3] Multiplication"<<endl;
	cout<<"[4] Division"<<endl;
	cout<<"[5] Exit"<<endl;
	
	cout<<"------------------"<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	
	system("cls");
	switch (choice){
		case 1:
			cout<<"-----Addition-----"<<endl;
			cout<<"Enter two numbers"<<endl;
			cin>>num1>> num2;
			result = num1 + num2;
			cout<<"Result is : "<<result<<endl;
			goto l;
			break;
		case 2:
			cout<<"-----Subtraction-----"<<endl;
			cout<<"Enter two numbers"<<endl;
			cin>>num1>> num2;
			result = num1 - num2;
			cout<<"Result is : "<<result<<endl;
			goto l;
			break;
		case 3:
			cout<<"-----Multiplication-----"<<endl;
			cout<<"Enter two numbers"<<endl;
			cin>>num1>> num2;
			result = num1 * num2;
			cout<<"Result is : "<<result<<endl;
			goto l;
			break;
		case 4:
			cout<<"-----Division-----"<<endl;
			cout<<"Enter two numbers"<<endl;
			cin>>num1>> num2;
			result = num1 / num2;
			if(result==0){
				cout<<"Error!\n\nDivision by 0 is invalid!\n\n";
				
			goto l;
			}
			else{
			cout<<"Result is : "<<result<<endl;
			}
			goto l;
			break;
		case 5:
			cout<<"-----Exiting-----"<<endl;
			cout<<"Thank you! Goodbye"<<endl;
			break;
		default:
			cout<<"Invalid input! please selecet 1,2,3,4 or 5!"<<endl;
			goto l;
			break;
			
	}
	
}
