
// C++ program to demonstrate 
// example of tolower() function. 
  
#include <iostream> 
using namespace std; 
  
int main() 
{ 
  
    char c = 'G'; 
  
    cout << c << " in lowercase is represented as = "; 
  
    // tolower() returns an int value there for typecasting 
    // with char is required 
    cout << (char)tolower(c); 
}
