#include <iostream>
using namespace std;

int countBits(int i) {
  int cnt = 0;
  while (i) {
    if (i & 1) {
      cnt++;
    }
    i >>= 1;
  }
  return cnt;
}

int main() {
  int k;
  int t = 0;
  while (cin >> k && k) {
    if (t++) cout << "\n";

    int arr[k];
    for (int i = 0; i < k; i++) {
      cin >> arr[i];
    }

    for (int m = 1 << k; m >= 0; m--) {
      if (countBits(m) != 6) {
        continue;
      }

      int t2 = 0;
      for (int i = 0; i < k; i++) {
        if (m & (1 << (k - i - 1))) {
          if (t2++) cout << " ";
          cout << arr[i];
        }
      }
      cout << "\n";
    }
  }
  return 0;
}
