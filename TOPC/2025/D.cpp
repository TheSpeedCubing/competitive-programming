#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string w;
        cin >> w;
        int n = w.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int inner = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                if (w[i] == w[j]) dp[i][j] = inner;
                else dp[i][j] = 1 + min({inner, dp[i + 1][j], dp[i][j - 1]});
            }
        }
        cout << dp[0][n - 1] << "\n";
    }
}