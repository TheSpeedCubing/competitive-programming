#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	int b;
	while(1) {
		cin >> b;
		if(a == b) {
			cout << b<<"\n";
			break;
		} else cout << b <<"\n";
	}
}

