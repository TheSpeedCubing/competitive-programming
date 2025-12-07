#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    
    cin.ignore();
    cin.ignore();
    
    int k = 0;
    while(t--) {
        if(k++) {
            cout << "\n";
        }

        map<string, int> m;
        
        int cnt = 0;
        while(getline(cin, s) && s != "") {
            cnt++;
            if(!m.count(s)) {
                m[s] = 1;
            } else {
                m[s]++;
            }
        }
        
        for(auto p : m) {
            cout << p.first << " ";
            printf("%.4f", (100.0 * m[p.first] / cnt));
            cout << "\n";
        }
    }
}