#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {

  string myText;
  
  
  
  ifstream MyReadFile("bscs1b_mabait_maganda.txt");

  while (getline (MyReadFile, myText)) {//this statement is for reading the text in the text file 
    cout << myText;
  }

  MyReadFile.close();
}

