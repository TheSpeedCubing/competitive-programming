#include <bits/stdc++.h>

using namespace std;

long long H(int n) {
    long long res = 0;
    
    long long lastA = 1, lastB = n;
    for(long long i = 2; i <= n; i++) {
        long long a = i; 
        long long b = n / i;
        
        res += lastA * (lastB - b) + lastB;
        
        if(a == b) {
            res += a;
            break;
        }
        if(a > b) {
            break;
        }
        lastA = a;
        lastB = b;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        cout << (n == 1 ? 1 : H(n)) << "\n";
    }
}