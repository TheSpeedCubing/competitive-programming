#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<pair<int, bool>> v;
        
        while(n--) {
            int i;
            cin >> i;
            v.emplace_back(abs(i), i > 0);
        }
        
        sort(v.rbegin(), v.rend());
        
        int cnt = 1;
        
        bool f = v[0].second;
        for(int i = 1; i < v.size(); i++) {
            if(f != v[i].second) {
                f = !f;
                cnt++;
            }
        }
        
        cout << cnt << "\n";
    }
}