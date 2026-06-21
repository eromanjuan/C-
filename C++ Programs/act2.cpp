#include <iostream>
using namespace std;

int main() {
    float grams;
    cout << "Please enter the weight in grams: ";
    cin >> grams;

    float kilograms = grams / 1000;
    cout << grams << " grams is equal to " << kilograms << " kilograms." << std::endl;

    return 0;
}

