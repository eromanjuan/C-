//C++ Program
#include <iostream>
using namespace std;

int main()
{
	double Lpkm, L, Km;
	cout << "Enter Liter: ";
	cin>>L;
	cout << "Distance traveled: ";
	cin>> Km;
	
	Lpkm = L/Km;
	
	cout<<"\n"<<Lpkm<<" L / Km";
	cout<<"\n"<<Lpkm*Km<<" Kmp / L";
	
	return 0;
}
