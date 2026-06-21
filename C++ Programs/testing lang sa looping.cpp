#include <iostream> 
using namespace std; 
int main() 
{ 
	int m, n; 
	for (m = 1, n = 1; m <= 5; m += 1, n += 2) { 
		cout << "iteration " << m << endl; 
		cout << "m is: " << m << endl; 
		cout << "j is: " << n << endl; 
	} 
	return 0; 
}

