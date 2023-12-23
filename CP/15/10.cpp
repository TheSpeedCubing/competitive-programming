#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    pair <int, int> boxes[100];

    int N, x, y, i = 0, result = 0, dp[100] = {0};
    cin >> N;
    while (i < N) {
      cin >> x >> y;
      boxes[i++] = make_pair(min(x, y), max(x, y));
    }

    sort(boxes, boxes + N);

    i = 0;
    while (i < N) {
      int m = 1, j = 0;
      while (j < i) {
        if (boxes[j].first < boxes[i].first && boxes[j].second < boxes[i].second) {
          m = max(m, dp[j] + 1);
        }
        j++;
      }

      result = max(result, m);
      dp[i++] = m;
    }
    cout << result << "\n";
  }
}