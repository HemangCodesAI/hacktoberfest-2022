#include <iostream>
using namespace std;

int main() {
	int x;
	cin>>x;
	if(x && (!(x & (x-1))))
	cout<<"Power of 2"<<endl;
	else
	cout<<"Not power of 2"<<endl;
	return 0;
}
