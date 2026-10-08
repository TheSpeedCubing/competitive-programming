#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        vector<long long> s(n, 0);
        
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        
        if(n < 4) {
            cout << "no solution\n";
            continue;
        }
        
        sort(s.begin(), s.end(), [](long long a, long long b) {
            return a > b;
        });
        
        int i = 0;
        while(1) {
            if(i == s.size()) {
                cout << "no solution\n";
                break;
            }
            long long d = s[i];
            
            bool found = false;
            
            for(int k = 0; k < n-2; k++) {
                if(k == i) continue;
                long long a = s[k];
                for(int l = k+1; l < n-1; l++) {
                    if(l == i) continue;
                    long long b = s[l];
                    if(a + b + s[n - 1 - (i == n - 1)] > d) {
                        continue;
                    }
					int nxt = (i == l + 1) ? l + 2 : l + 1;
					if(nxt >= n || d > a + b + s[nxt]) {
                        break;
                    }
                    for(int m = l+1; m < n; m++) {
                        if(m == i) continue;
                        long long sum = a + b + s[m];
                        if(d > sum) {
                            break;
                        }
                        if(d == sum) {
                            cout << d << "\n";
                            found = true;
                            goto c;
                        }
                    }
                }
            }
            c: {
                if(found) {
                    break;
                }
            }
            
            i++;
        }
    }
}