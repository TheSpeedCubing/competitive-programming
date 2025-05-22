#include<bits/stdc++.h>

using namespace std;

int main() {
  int size = 30001;
  long long dp[size] = {1};
  
  for (int c : {1, 5, 10, 25, 50}) {
    for (int i = c; i < size; i++) {
      dp[i] = dp[i] + dp[i - c];
    }  
  }
  
  int n;
  while (cin >> n){
    if (dp[n] == 1)
      cout << "There is only 1 way";
    else
      cout << "There are " << dp[n] << " ways";
    cout << " to produce " << n << " cents change." << "\n";
  }
}
