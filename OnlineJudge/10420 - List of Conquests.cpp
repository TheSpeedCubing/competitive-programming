#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    cin.ignore();
    
    map<string, int> m;
    while(t--) {
        getline(cin, s);
        stringstream ss(s);
        ss >> s;
        if(!m.count(s)) {
            m[s] = 1;
        } else {
            m[s]++;
        }
    }
    for(auto p : m) {
        cout << p.first << " " << p.second << "\n";
    }
}