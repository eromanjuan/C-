#include <iostream>
using namespace std;

int main() {
  string letters[2][2][2] = {
    {
      { "A", "B" },
      { "C", "D" }
    },
    {
      { "E", "F" },
      { "G", "H" }
    }
  };

  for (int i = 0; i < 2; i++) {
  	cout<<endl;
    for (int j = 0; j < 2; j++) {
    	
  	cout<<endl;
      for (int k = 0; k < 2; k++) {
        cout << letters[i][j][k] << " ";
      }
    }
  }
  return 0;
}

