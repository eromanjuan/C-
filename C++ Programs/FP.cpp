#include <iostream>
#include <string>
using namespace std;

void myFunction(string fname) {
  cout << fname << " Eugenio\n";
}

int main() {
  string a = "Juan";
  //cout<<"Enter name :";cin>>a;
  myFunction(a);
  return 0;
}

