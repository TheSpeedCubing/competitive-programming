#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[5005][55];

string a, b;

bool judge(int mid) {
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		if (dp[i][m] <= mid)
			dp[i][0] = 0;
		for (int j = 0; j <= m; j++) {
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
		}
	}
	return dp[n][m] <= mid;
}

int main() {
    int t;
    cin >> t;
	while (t--) {
	    cin >> b >> a;
	    n = a.length();
	    m = b.length();
	    
		int l = 0, r = m;
		while (l < r) {
			int mid = (l + r) / 2;
			if (judge(mid)) r = mid;
			else l = mid + 1;
		}
		cout << l <<"\n";
	}
}
