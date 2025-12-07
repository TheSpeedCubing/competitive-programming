#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int size = 40;
    int f[size] = {0, 1};
    for(int i = 2;i<size;i++) {
        f[i] = f[i-1] + f[i-2];
    }
    
    
    while(n--) {
        int k;
        cin >> k;
        cout << k << " = ";
        string s;
        bool pr = false;
        for(int j = size-1; j >= 2; j--) {
            if(f[j] <= k) {
                k -= f[j];
                cout << 1;
                pr = true;
            } else if(pr) {
                cout << 0;
            }
        }
        cout << " (fib)\n";
    }
}