#include <bits/stdc++.h>

using namespace std;

int main() {
    int q, p;
    
    while(cin>>q>>p) {
      int cnt[100000] = {}, index[100000];
      
      cout << q/p;
      q = 10 * (q < p ? q : q % p);
      
      cnt[q]++;
      index[q] = 0;
      
      string s;
      
      int i = 1;
      while(true) {
        s += to_string(q/p);
        q = 10*(q - q/p*p);
        if(cnt[q]++) {
          break;
        }
        index[q] = i++;
        if (!q) {
        	  s += "0";
            break;
        }
      }
      
      int bracketIndex = index[q];
      
      cout 
           << "."
           << s.substr(0, bracketIndex)
           << "("
           << s.substr(bracketIndex)
           << ")\n";
    }
}
