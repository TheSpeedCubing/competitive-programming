#include<bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a; // t, ignored
  
  while(cin >> a >> b) {
    a += b; // pins can be fully inserted into rows in all cases
    
    int level = 1;
    while(a >= level) {
       a -= (level);
       level++;
    }
    cout << level - 1;
  }
}
