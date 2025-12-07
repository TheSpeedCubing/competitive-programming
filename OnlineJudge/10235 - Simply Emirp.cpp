#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int size = 1000001;
    bool notp[size] = {};

    for(int i = 2; i <= sqrt(size);i++) {
        if(!notp[i]) {
            int k = i * i;
            while(k < size) {
                notp[k] = true;
                k += i;
            }
        }
    }
    
    string n;
    while(cin >> n) {
        int i = stoi(n);
        reverse(n.begin(), n.end());
        int i2 = stoi(n);
        
        if(!notp[i]) {
            if(!notp[i2] && i != i2) {
                cout << i << " is emirp.\n";
            } else {
                cout << i << " is prime.\n";
            }
        } else {
            cout << i << " is not prime.\n";
        }
    }
}