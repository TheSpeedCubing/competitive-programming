#include<bits/stdc++.h>

using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if(b - a == c - b) {
		cout << "secret " << (b-a) << "\n";
	} else {
		cout << "not secret\n";
	}
}