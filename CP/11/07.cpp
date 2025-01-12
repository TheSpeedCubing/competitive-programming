#include <iostream>

using namespace std;

int main()
{
	int n, q;
	cin >> n;
	//should be int
	short a[n], acc[n], backSlot = 0, i = 0;
	for(;i<n;i++){
		cin >> a[i];
		backSlot += (i % 2 ? -a[i] : a[i]);
		acc[i] = backSlot;
	}
	cin >> q;
	while(q--) {
		cin >> i >> n;
		cout << ((i%2 ? 1 : -1) * (acc[n - 1] - acc[i - 2]))<<"\n";
	}
}
