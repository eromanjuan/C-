#include <iostream>
#include <string>

using namespace std;

int main() {
    int numNames;
    cout << "Enter the number of names you want to input: ";
    cin >> numNames; //number of names you want to enter ** ilang names iinput
    

    // Create an array to store the names dito masasave lahat ng names
    string names[numNames];

    // Input the names
    for (int i = 0; i < numNames; ++i) {
        cout << "Enter name " << i + 1 << ": ";
        cin >> names[i];
    }

    // Print the names
    cout << "The names you entered are:" << endl;
    for (int i = 0; i < numNames; ++i) {
        cout << names[i] << endl;
    }

    return 0;
}

