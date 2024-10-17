#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    int count['Z'+1] = {};
    string s;
    cin >> t;
    getchar();
    
    int maxc = 0;
    while(t--) {
        getline(cin,s);
        for(char c : s) {
            if(isalpha(c)) {
                count[toupper(c)]++;
                maxc = max(count[toupper(c)], maxc);
            }
        }
    }
    for(int i = maxc; i > 0;i--) {
        for(char c = 'A'; c <= 'Z';c++) {
            if(count[c] == i) {
                cout << c << " " << count[c] << "\n";
            }
        }
    }
}
