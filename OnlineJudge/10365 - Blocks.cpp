#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        
        int area = 2147483647;
        for(int i = 1; i <= n; i++) {
            if(n % i != 0) {
                continue;
            }
            
            for(int j = 1; j <= n; j++) {
                if(n / i % j != 0) {
                    continue;
                }
                
                int x = n / i / j;
                int y = i;
                int z = j;
                
                area = min(area, 2 * (x * y + x * z + y * z));
            }
        }
        
        cout << area << "\n";
    }
}