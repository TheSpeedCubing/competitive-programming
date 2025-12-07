#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    int T;
    while(t--) {
        T++;
        
        string s1, s2;
        cin >> s1 >> s2;
        
        int i1 = bitset<32>(s1).to_ulong();
        int i2 = bitset<32>(s2).to_ulong();

        cout << "Pair #" << T << ": ";
        
        if(__gcd(i1, i2) == 1) {
            cout << "Love is not all you need!\n";
        } else {
            cout << "All you need is love!\n";
        }
    }
}