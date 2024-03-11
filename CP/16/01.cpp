#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, a, b;
  char c;
  while (cin >> N >> M && N + M) {
      int * ref[1024];
      int val[1024] = {}, i = 1024;

      while (i--) {
        ref[i] = & val[i];
      }

      while (M--) {
        cin >> c >> a >> b;
        cin.ignore();
        if (c == 'A')
          *ref[a] += b;
        if (c == 'P')
          ref[a] = ref[b];
        if (c == 'S')
          swap( * ref[a], * ref[b]);
        if (c == 'X')
          swap(ref[a], ref[b]);
      }
      for (int i = 0; i < N; i++) {
        cout << *ref[i] << (i == N - 1 ? "\n" : " ");
      }
    }
  }