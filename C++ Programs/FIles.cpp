#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	
  string myText;
  cout<<"Enter your string:\n";
  getline(cin, myText);
  ofstream MyWriteFile("rom.txt");
  MyWriteFile <<myText;
  MyWriteFile.close();

  // Read from the text file from the file named filename.txt
  ifstream MyReadFile("rom.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
  }

  // Close the file
  MyReadFile.close();
}
