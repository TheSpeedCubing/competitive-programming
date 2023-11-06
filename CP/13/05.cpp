#include <iostream>
using namespace std;

int main()
{
	unsigned long long t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << "146520"[(n-1)%6] <<"\n";
	}
}
