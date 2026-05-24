#include <bits/stdc++.h>

using namespace std;

// b, n5, n10
int dp[200][500][500];

int cost = 8;

int c;
int total;

int f(int b, int n5, int n10) {
    if(b == c) {
        return 0;
    }
    if(dp[b][n5][n10] != -1) {
        return dp[b][n5][n10];
    }
    
    int k = 2147483647;
    
    int n1 = total - b * cost - n5 * 5 - n10 * 10;
    
    // 1 1 1 1 1 1 1 1
    if(n1 >= 8) {
        k = min(k, 8 + f(b + 1, n5, n10));
    }
    // 5 1 1 1
    if(n5 >= 1 && n1 >= 3) {
        k = min(k, 4 + f(b + 1, n5 - 1, n10));
    }
    // 10 1 1 1
    if(n10 >= 1 && n1 >= 3) {
        k = min(k, 4 + f(b + 1, n5 + 1, n10 - 1));
    }
    // 5 5
    if(n5 >= 2) {
        k = min(k, 2 + f(b + 1, n5 - 2, n10));
    }
    // 10
    if(n10 >= 1) {
        k = min(k, 1 + f(b + 1, n5, n10 - 1));
    }
    
    dp[b][n5][n10] = k;

    return k;
}

int main() {
    int t, n1, n5, n10;
    cin >> t;
    while(t--) {
        cin >> c >> n1 >> n5 >> n10;
        
        total = n1 + n5 * 5 + n10 * 10;
        
        memset(dp, -1, sizeof(dp));
        
        cout << f(0, n5, n10) << "\n";
    }
}
