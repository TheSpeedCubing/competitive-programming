#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while(cin >> n && n) {
        vector<int> v;
        
        for(int i = 1;i<=n;i++) {
            v.push_back(i);
        }
        
        vector<int> erased;
        while(v.size() != 1) {
            erased.push_back(*v.begin());
            v.erase(v.begin());
            v.push_back(*v.begin());
            v.erase(v.begin());
        }
        cout << "Discarded cards:";
        for(int i = 0;i<n-1;i++) {
            cout << (i==0? " " : ", ") << erased[i];
        }
        cout << "\nRemaining card: " << v[0] << "\n";
    }
}