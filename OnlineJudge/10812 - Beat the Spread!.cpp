#include <bits/stdc++.h>

using namespace std;

/*
  a + b = sum
  a - b = diff
  a = (sum + diff) / 2
  b = sum - a
*/

int main() {
    int t;
    cin >> t;
    
    int sum, diff;
    while(t--) {
        cin >> sum >> diff;
        
        if ((sum + diff) % 2 != 0) {
            cout << "impossible\n";
            continue;
        }
        
        int a = (sum + diff) / 2;
        int b = sum - a;
        if(a >= 0 && b >= 0) {
            cout << a << " " << b << "\n";
        } else {
            cout << "impossible\n";
        }
    }
}