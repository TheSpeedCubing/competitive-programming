#include <bits/stdc++.h>

using namespace std;


int main() {
  int w, l, f = 0;
  while(cin >> w >> l) {
    if(f++) {
      cout << "\n";
    }
    char n[w+1];
    int c = 0, line = 1;
    while(l > 0) {
       memset(n,' ',sizeof(n));
       int i;
       for(i = 0; i < w && l; i++) {
    	 l--;
         n[line % 2 ? i : w - i - 1] = (c++ % 26 + 'a');
       }
       n[line % 2 ? i : w] = '\0';
       line++;
       cout << n << "\n";
    }
  }
}
