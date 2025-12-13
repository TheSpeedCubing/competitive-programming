#include <bits/stdc++.h>

using namespace std;

struct Op {
  string type;
  int pos;
  char c;
};

vector<Op> backtracking(string a, string b, vector<vector<int>> dp) {
    
    int i = a.length();
    int j = b.length();
    
    vector<Op> ops;
    while(i > 0 || j > 0) {
      if(i > 0 && j > 0 && a[i-1] == b[j-1]) {
        i--;
        j--;
        continue;
      }
      if(i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1] + 1) {
        ops.push_back({"Replace", i, b[j-1]});
        i--;
        j--;
        continue;
      }
      
      if(i > 0 && dp[i][j] == dp[i-1][j] + 1) {
        ops.push_back({"Delete", i, 0});
        i--;
        continue;
      }
      
      if(j > 0 && dp[i][j] == dp[i][j-1] + 1) {
        ops.push_back({"Insert", i+1, b[j-1]});
        j--;
        continue;
      }
    }
    reverse(ops.begin(), ops.end());
    return ops;
}

void editDistance(string a, string b) {
    
    int n = a.length();
    int m = b.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) 
        dp[i][0] = i;
    for (int j = 0; j <= m; j++) 
        dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1,
                    dp[i - 1][j - 1] + 1
                });
            }
        }
    }
    
    cout << dp[n][m] << "\n";
    
    int k = 1;
    int shift = 0;
    for(Op o : backtracking(a, b, dp)) {
      cout << (k++) << " " << o.type << " " << (shift + o.pos);
      
      if(o.type != "Delete") {
        cout << "," << o.c;
      }
      cout << "\n";
      
      if(o.type == "Delete") {
        shift--;
      }
      if(o.type == "Insert") {
        shift++;
      }
    }
}


int main() {
  string s1, s2;
  
  int k = 0;
  while(getline(cin, s1)) {
    if(k++) cout << "\n";
    getline(cin, s2);
    editDistance(s1, s2);
  }
}
