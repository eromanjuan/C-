#include <iostream>
using namespace std;
//Switch case example
int main() {
    char oper;
    float num1, num2;
	l:
    cout << "\nEnter an operator (+, -, *, /): ";
    cin >> oper;

    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;

    switch (oper) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            
			break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            goto l;
			break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            goto l;
			break;
        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            goto l;
			break;
            
        default:
            cout << "Error! The operator is not correct.";
            break;
    }

    return 0;
}
//roman juan g eugenio i
