#include <iostream>
using namespace std;
int main() {
  double number, sum = 0;

  // the body of the loop is executed at least once
  do {
    cout<<"Enter a number: ";
    cin>>number;
    sum += number;
  }
  while(number != 0.0);

  cout<<"Sum :"<<sum;

  return 0;
}
