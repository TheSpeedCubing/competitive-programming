#include <bits/stdc++.h>

using namespace std;

int main() {

  int t, n, in, r;
  cin >> t;
  while (t--) {
    cin >> n;
    int arr[1000], i = 0, b = 0;

    while (i < n)
      cin >> arr[i++];

    cin >> r;

    for (int i = 0; i < n - 2; i++)
      for (int j = i + 1; j < n - 1; j++)
        for (int k = j + 1; k < n; k++)
          if (arr[i] + arr[j] + arr[k] == r)
            b = 1;

    cout << (b ? "Yes\n" : "No\n");
  }
}
