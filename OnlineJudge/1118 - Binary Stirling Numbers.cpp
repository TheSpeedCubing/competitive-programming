#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int T;
  cin >> T;
  while (T--) {
  	int m,n;
  	cin >> m >> n;
    //from wikipedia
  	cout << (((m - n) & ((n-1) >> 1)) == 0) <<"\n";
  }
}
