#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long long p[61];
    
    for(int i = 0; i < 62;i++) {
        p[i] = 1LL << i;
    }
    
    int t;
    long long x;
    cin >> t;
    while(t--) {
        cin >> x;
        
        long long ans = x;
        for(int i = 0; i < 62;i++) {
            for(int j = i; j < 62;j++) {
                long long r = llabs(p[i] + p[j] - x);
                ans = min(ans, r);
            }
        }
        cout << ans << "\n";
    }
}
