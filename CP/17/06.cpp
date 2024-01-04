#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, n, k, a, b, c;
  while (cin >> n && n) {
    int arr[10000], arr2[10000], i = n, sum = 0;
       
    while(i--)
      cin >> arr[i];
      
    sort(arr, arr + n);
    
    cin >> T;
    while (T--) {
      cin >> k >> a >> b >> c;
      int i = n;
      while(i--)
      	 arr2[i] = (a * arr[i] + b) % c;
      sort(arr2, arr2 + n);
      sum += arr2[k-1];
    }
    cout << sum <<"\n";
  }
}
