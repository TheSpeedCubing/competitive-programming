#include <bits/stdc++.h>

using namespace std;


int main() {
    int flag = 0, n;
    while(cin >> n){
        if(flag++)
          cout <<"\n";
        int arr[100][100] = {0},
            x = 0,
            y = n/2,
            i = 1;
        while(i <= n*n) {
            arr[x][y] = i;
            if(x == 0 && y == n-1){
                x++;
            } else if(x == 0) {
                x = n - 1;
                y++;
            } else if(y == n - 1) {
                x--;
                y = 0;
            } else if(arr[x-1][y+1]) {
                x++;
            } else {
              x--;
              y++;
            }
            i++;
        }
      for (int i = 0; i < n*n; i++) {
        printf("%*d",to_string(n*n).length(),arr[i/n][i%n]);
        cout << (i%n == n - 1 ? "\n" : " ");
      }
    }
}