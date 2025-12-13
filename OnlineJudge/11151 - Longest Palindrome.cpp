#include <bits/stdc++.h>

using namespace std;

int LCS(string a, string b) {
    
    int n = a.length();
    int m = b.length();

    int dp[n + 1][m + 1] = {};
        
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
        
    return dp[n][m];
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        string s2 = s;
        reverse(s2.begin(), s2.end());
        cout << LCS(s, s2) << "\n";
    }
}
