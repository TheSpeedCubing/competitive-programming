#include <bits/stdc++.h>

using namespace std;

string s;
int k, f, cnt[128] = {};

void search(int level, char last, string lastStr) {
  for (char c = last; c <= 'z'; c++) {
    if (cnt[c]) {
    	if (level == k) {
        cout << lastStr << c << "\n";
      } else {
        cnt[c]--;
        search(level + 1, c, lastStr + c);
        cnt[c]++;
      }
    }
  }
}

int main() {
  while (cin >> s >> k) {
  	if(f++)
  	  cout <<"\n";
    for (char c: s) {
      cnt[c]++;
    }
    search(1, 'a', "");
    fill(cnt,cnt+128,0);
  }
}