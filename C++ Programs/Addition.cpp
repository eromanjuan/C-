#include <iostream>
using namespace std;
asd
int main() {
//grade
  double pre, mid, semi, fin, sum, ave;
  
  cout << "Prelim: ";
  cin >> pre;
  cout << "Midterm: ";
  cin >> mid;
  cout << "Semi: ";
  cin >> semi;
  cout << "Final: ";
  cin >> fin;  
  sum = pre+ mid+ semi+ fin;
  ave = sum/4;
  
  cout << "Ave is : " << ave;
  return 0;
}

