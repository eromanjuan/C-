#include <iostream>
using namespace std;

// Function prototypes
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main() {
    char op;
    float num1, num2;
    
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    
    switch(op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << add(num1, num2);
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << subtract(num1, num2);
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << multiply(num1, num2);
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << divide(num1, num2);
            break;
        default:
            cout << "Error! Operator is not correct";
            break;
    }
    
    return 0;
}

// Function definitions
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error! Division by zero.";
        return 0;
    }
}


