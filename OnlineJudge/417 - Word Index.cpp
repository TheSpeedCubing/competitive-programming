#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int arr[5][128];
    
    // L1
    for(char c = 'a'; c <= 'z'; c++) {
        arr[0][c] = c - 'a' + 1;
    }
    
    // L2 ~ 5
    for(int l = 1; l <= 4; l++) {
                              // z, y, x, w
        arr[l]['a'] = arr[l-1]['z' - l + 1] - arr[l-1]['a'];
        for(char c = 'b'; c <= 'z'; c++) {
                                            // z, y, x, w
            arr[l][c] = arr[l][c-1] + arr[l-1]['z' - l + 1] - arr[l-1][c];
        }
    }
    
    string s;
    while(cin >> s) {
        int sum = 0;
        char mx = 0;
        for(int i = 0;i<s.length();i++) {
           if(s[i] <= mx) {
               sum = 0;
               break;
           } else mx = s[i];
           sum += arr[s.length()-i-1][s[i]]; 
        }
        cout << sum << "\n";
    }
}
