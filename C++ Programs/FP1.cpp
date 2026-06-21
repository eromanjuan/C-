#include <iostream>
#include <string>
using namespace std;

void myFunction(string country = "No country") {
  cout << country << "\n";
}

int main() {
  myFunction("Sweden");
  myFunction("India");
  myFunction();
  myFunction("USA");
  return 0;
}

