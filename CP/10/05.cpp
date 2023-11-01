#include <iostream>
using namespace std;

int buf[1024], Z;

void attempt(int key) {
  buf[Z] = 0x66666666;
  for (int i = 1; key; i++) {
    if (buf[i] == 0x33333333) {
      buf[i] = 0x66666666;
      key--;
    }
  }
}

void searchBuf(int i) {
  while(buf[Z] == 0x66666666 || buf[Z] == i)
     Z--;
}


int main() {
  int n, m;
  while (cin >> n >> m) {
    int i = 0, M = m, M2 = m;
    fill(buf,buf + 1024, 0x33333333);
    
    while (M--) {
      cin >> Z;
      buf[Z] = 0x99999999;
    }
    
    while(M2--) {
      Z = m * n;
      searchBuf(0x66666666);
      if (buf[Z] == 0x99999999) {
      	i++;
      	attempt(n-1);
      }
      if (buf[Z] == 0x33333333) {
        buf[Z] = 0x66666666;
        searchBuf(0x33333333);
      	attempt(n-2);
      }
    }
    cout << i << "\n";
  }
}