#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << (b - a == 2 && isPrime(a) && isPrime(b) ? "Y" : "N") << "\n";
    }
}