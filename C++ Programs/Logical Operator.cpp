#include <iostream>
using namespace std;

int main() {
    bool a = true;
    bool b = false;

    // Logical AND (&&)
    if (a && b) {
        cout << "Both a and b are true" << endl;
    } else {
        cout << "Either a or b is false" << endl;
    }

    // Logical OR (||)
    if (a || b) {
        cout << "At least one of a or b is true" << endl;
    } else {
        cout << "Both a and b are false" << endl;
    }

    // Logical NOT (!)
    if (!b) {
        cout << "b is false" << endl;
    } else {
        cout << "b is true" << endl;
    }

    return 0;
}

