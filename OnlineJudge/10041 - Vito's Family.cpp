#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,c,i;
    cin >>t;
    while(t--) {
        cin >> c;
        int arr[c];
        for(int i = 0;i<c;i++) {
            cin >> arr[i];
        }
        
        int minimum = 2147483647;
        for(int i = 0;i<c;i++) {
          int sum = 0;
          for(int j = 0;j<c;j++) {
              sum += abs(arr[i]-arr[j]);
          }
          minimum = min(minimum,sum);
        }
        cout << minimum <<"\n";
    }
}
