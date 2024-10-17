#include <bits/stdc++.h>

using namespace std;

int main() {
    long long i;
    while(cin >> i && i) {
    	long long f = sqrt(i);
    	cout << (f * f == i ? "yes\n" : "no\n");
    }
}
