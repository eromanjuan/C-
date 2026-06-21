#include<iostream>
using namespace std;

int main()
{
	int pre, mid, semi, final;
	cout<<"Enter the prelim grade :";
	cin>>pre;
	cout<<"Enter the midterm grade :";
	cin>>mid;
	cout<<"Enter the semi-final grade :";
	cin>>semi;
	cout<<"Enter the final grade :";
	cin>>final;
	cout<<(pre+mid+semi+final)/4;
	return 0;
}
