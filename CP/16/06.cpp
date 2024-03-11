#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a;
    while (cin >> n >> k) {
    	map<int,int> arr,arr2;
        int cnt = 0, cnt2 = 0, 
        used = 0,used2 = 0,
        f = 0, f2 = 0, 
        t = 0, t2 = 0, 
        r = 0, r2 = 0, 
        g = 0, g2 = 0,
        
        m = 0;
        
        while(n--) {
            scanf("%1d", &a);
            
            if (a == 0) {
                g2 = max(g2, ++r2);
                r = 0;
                if (used >= k) {
                    cnt -= (arr[f - k] + 1);
                } else 
                    used++;
                arr[f++] = t2;
                t2 = 0;
                t++;
            } else {
                g = max(g, ++r);
                r2 = 0;
                if (used2 >= k) {
                    cnt2 -= (arr2[f2 - k] + 1);
                } else used2++;
                arr2[f2++] = t;
                t=0;
                t2++;
            }
            
            m = max(m, max(++cnt, ++cnt2));
        }
        
        cout << (k ? m : max(g, g2)) <<"\n";
    }
}
