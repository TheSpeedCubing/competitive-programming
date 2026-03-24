#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int T = 1;T<=t; T++) {
        int n;
        cin >> n;
        
        int n2 = n;
        
        bool f = false;
        
        set<int> s;
    
        while(1) {
            s.insert(n);
            
            int sum = 0;
            while(n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if(sum == 1) {
                f = true;
                break;
            }
            if(sum == n2 || s.count(sum)) {
                break;
            }
            n = sum;
        }
        
        cout << "Case #" << T <<": " << n2 << " is " << (f ? "a Happy" : "an Unhappy") << " number.\n";
    }
}