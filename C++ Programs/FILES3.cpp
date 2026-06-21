#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // open a text file for writing
    ofstream my_file("example.txt");

    // check the file for errors
    if(!my_file) {
        cout << "Error: Unable to open the file." << endl;
        return 1; 
    }

    // write multiple lines to the file
    my_file << "Line 1" << endl;
    my_file << "Line 2" << endl;
    my_file << "Line 3" << endl;

    // close the file
    my_file.close();

    return 0;
}
