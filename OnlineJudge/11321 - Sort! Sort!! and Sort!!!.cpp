#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        cout << n << " " << m << "\n";
        if(n == 0 && m == 0) {
            break;
        }
        
        vector<int> v;
        
        int i;
        while(n--) {
            cin >> i;
            v.push_back(i);
        }
        
        sort(v.begin(), v.end(), [m](int a, int b) {
            int ra = a % m;
            int rb = b % m;
            
            // sort by modulo
            if(ra != rb) {
                return ra < rb;
            }
            
            bool aOdd = a % 2 != 0;
            bool bOdd = b % 2 != 0;
            
            // diff -> odd first
            if(aOdd ^ bOdd) {
                return a % 2 != 0;
            }
            
            // two odds -> larger first
            if(aOdd && bOdd) {
                return a > b;
            }
            
            // two evens -> smaller first
            return a < b;
        });
        
        for(int i : v) {
            cout << i << "\n";
        }
    }
}