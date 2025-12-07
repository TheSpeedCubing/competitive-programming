#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    
    while(getline(cin, a)) {
        getline(cin, b);
        
        int aa[128] = {};
        int bb[128] = {};
        
        for(char c : a) {
            aa[c]++;
        }
        
        for(char c : b) {
            bb[c]++;
        }
        
        for(char c = 0; c < 127; c++) {
            for(int i = 0;i<min(aa[c], bb[c]);i++) {
                cout << c;
            }
        }
        cout << "\n";
    }
}