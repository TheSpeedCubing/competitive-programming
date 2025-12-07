#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while(cin >> s && s != "0") {
        cout << s;
        
        int a = 0, b = 0;
        for(int i = 0;i<s.length();i++) {
            if(i % 2 == 0) {
                a += s[i] - '0';
            } else {
                b += s[i] - '0';
            }
        }
        if(abs(a-b) % 11 == 0) {
            cout << " is a multiple of 11.\n";
        } else {
            cout << " is not a multiple of 11.\n";
        }
    }
}