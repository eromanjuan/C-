#include <iostream>
using namespace std;

int main() {
  string letters[2][4] = {
    { "A", "B", "C", "D" }, //0,0 0,1 0,2 0,3
    { "E", "F", "G", "H" } //1,0 1,1 1,2 1,3
  };

  for (int i = 0; i < 2; i++) {
  	cout<<endl;
    for (int j = 0; j < 4; j++) {
      cout << letters[i][j] << " ";
    }
  }
  return 0;
}

