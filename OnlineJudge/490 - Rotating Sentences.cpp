#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s[101] = {};
    
    int l = 0;    
    
    int m = 0;
    while(getline(cin, s[l])) {
        m = max((int) s[l].length(), m);
        l++; 
    }
    
    for(int i = 0;i < m;i++) {
        for(int j = l-1;j>=0;j--) {
            if(s[j].length() <= i) {
                cout << " ";
            } else cout << s[j][i];
        }
        cout << "\n";
    }
}