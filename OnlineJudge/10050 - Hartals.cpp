#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        bool arr[n + 1] = {};
        
        int p, h;
        cin >> p;
        while(p--) {
            cin >> h;
            
            int h2 = h;
            while(h2 <= n) {
                arr[h2] = true;
                h2 += h;
            }
        }
        
        int i = 6;
        while(i <= n) {
           arr[i] = false;
           arr[i+1] = false;
           i += 7;
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(arr[i])
                cnt++;
        }
        cout << cnt << "\n";
    }
}