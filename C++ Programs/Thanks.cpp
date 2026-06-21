#include <iostream>
#include <windows.h>
using namespace std;
void clearScreen() {
    system("CLS");
}

void printThankYou(int position) {
    for (int i = 0; i < position; ++i) {
	cout << " ";
    }
    cout << "THANK YOU GUYS" << endl;
}

int main() {
    const int delay = 10; 
    const int maxPosition = 100000; 

    for (int i = 0; i < maxPosition; ++i) {
        clearScreen();
        printThankYou(i);
        Sleep(delay);
    }

    return 0;
}

