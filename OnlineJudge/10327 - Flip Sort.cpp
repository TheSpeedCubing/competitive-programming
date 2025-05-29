#include<iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    int arr[n];

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
          cnt++;
        }
      }
    }
    cout << "Minimum exchange operations : " << cnt << "\n";
  }
}
