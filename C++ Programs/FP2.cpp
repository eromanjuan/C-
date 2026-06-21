#include <iostream>
#include <string>
using namespace std;

void myFunction(string fname,int age) {
  cout << fname << " Eugenio,"<<age<<endl;
}

int main() {
  
  myFunction("Juana",12);
  myFunction("Romana",10);
  myFunction("Juliana",8);
  return 0;
}

