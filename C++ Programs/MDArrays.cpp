#include <iostream>
using namespace std;

int main() {
  string letters[2][4] = {
    { "A", "B", "C", "D" },
    { "E", "F", "G", "H" }
  };
  
  cout << letters[1][3];
  cout << letters[0][0];
  cout<<"?";
  return 0;
}

