#include <bits/stdc++.h>

using namespace std;

int main() {
    int i;
    vector<int> v;
    while(cin >> i) {
        v.push_back(i);
        sort(v.begin(),v.end());
        if(v.size() % 2 == 1) {
            cout << v[v.size()/2] << "\n";
        } else {
            cout << (v[v.size()/2] + v[v.size()/2-1])/2 << "\n";
        }
    }
}
