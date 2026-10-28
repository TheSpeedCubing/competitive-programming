#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<long long,long long>> v(n);
    
    for(auto p : v) {
        cin >> p.first >> p.second;
    }
    
    sort(v.begin(), v.end());
    
    int best = 1, cnt = 1;
    long long maxR = v[0].second;
    
    for(int i = 1;i<n;i++) {
        if(v[i].first <= maxR) {
            cnt++;
        } else {
            cnt = 1;
        }
        maxR = max(maxR, v[i].second);
        best = max(best, cnt);
    }
    cout << best << "\n";
}