#include<bits/stdc++.h>

using namespace std;

int main() {
  vector<string> d; 
  int seed;
  cin >> seed;
  srand(seed);
  for (int i = 0; i < 52; i++) {
  	string a;
    cin >> a;
    d.push_back(a);
    int j = 2;
    for (char c: "23456789TJQKA") {
      if (c == d[i][1]) {
        d[i][1] = j;
        break;
      }
      j++;
    }
  }
  int T, base = 52, cnt = 0;
  cin >> T;
  while (T) {
    cnt++;
    int x = rand() % base;
    swap(d[x], d[base - 1]);

    int n[5], s[5], i = 0,
    diff = 1,
    isFlush = 1,
    isStraight = 1;
    
    while(i<5) {
      n[i] = d[i][0];
      s[i] = d[i][1];
      i++;
    }

    sort(s, s + 5);

    i = 0;
    while (i < 4) {
      int t = s[i + 1] - s[i];
      if(t != 1 && (t != 9 || i != 3))
        isStraight = 0;

      if (t)
        diff++;
      if (n[i] != n[i + 1])
        isFlush = 0;
      i++;
    }
    if (isFlush || isStraight || diff == 2) {
      cout << cnt <<":";
      cnt = 0;
      i = 0;
      while(i < 5) {
        cout << " " << d[i][0] << "  23456789TJQKA"[d[i][1]];
        i++;
      }
      cout << "\n";
      rotate(d.begin(), d.begin() + 5, d.end());
      T--;
    }

    base = base == 2 ? 52 : base - 1;
  }
}
