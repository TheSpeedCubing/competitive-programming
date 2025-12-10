#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    while(cin >> n && n >= 0) {
        cout << (n*(n+1)/2 + 1) << "\n";
    }
}