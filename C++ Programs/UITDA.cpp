#include <iostream>
using namespace std;

int main() {
    int numbers[2][3];

    cout << "Enter 6 numbers: " << endl;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> numbers[i][j];
        }
    }

    cout << "The numbers are: " << endl;

    for (int i = 0; i < 2; ++i) {
    	cout<<endl;
        for (int j = 0; j < 3; ++j) {
        	
            cout << "numbers[" << i << "][" << j << "]: " << numbers[i][j]<<" " ;
        }
    }

    return 0;
}
