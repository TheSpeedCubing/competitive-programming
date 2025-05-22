#include<bits/stdc++.h>

using namespace std;

int main() {
  int t = 0;
  int N;
  while (cin >> N) {
    t++;
    int arr[N];
    bool f = true;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
      if (arr[i] < 1) {
        f = false;
      }
    }

    bool dup[20001] = {};
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        if (!dup[arr[i] + arr[j]]) {
          dup[arr[i] + arr[j]] = true;
        } else f = false;
        if (arr[i] > arr[j]) 
           f = false;
      }
    }
    cout << "Case #" << t << ": It is ";
    if (f) cout << "a B2-Sequence.\n\n";
    else cout << "not a B2-Sequence.\n\n";
  }
}
