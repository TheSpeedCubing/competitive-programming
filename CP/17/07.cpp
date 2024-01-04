#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, m , n, x , y;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case " << t << ":\n";
    cin >> m >> n;

    int arr[200][200] = {0};

    for (int i = 0; i < m * n; i++) {
      cin >> arr[i / n][i % n];
    }

    string prefix;
    while (cin >> prefix && prefix != "#") {
    	int m2 = m, n2 = n, i = m * n;
      if (prefix == "reverse") {
      	bool swapped[40000] = {0};
        while(i--) {
          	int a = i/n, b = i%n, 
          	   x = m - a - 1, y = n - b - 1;
            if (!swapped[x*200+y])
              swap(arr[a][b], arr[x][y]);
            swapped[a*200+b] = true;
          }
      } else if (prefix == "print") {
        for (int i = 0; i < m * n; i++)
           cout << arr[i/n][i%n] << ((i+1)%n ? " " : "\n");
        cout << "\n";
      } else {
        cin >> x >> y;
        if (prefix == "addcol")
            while(m2--)
              arr[m2][x] += y;
        if (prefix == "addrow")
            while(n2--)
              arr[x][n2] += y;
        if (prefix == "xrow")
            while(n2--)
              swap(arr[x][n2], arr[y][n2]);
        if(prefix == "xcol")
            while(m2--)
              swap(arr[m2][x], arr[m2][y]);
        if(prefix == "reshape") {
          int arr2[200][200] = {0}, i = x * y;
          while(i--)
               arr2[i/y][i%y] = arr[i/n][i%n];
          m = x;
          n = y;
          memcpy(arr,arr2,200*200 * sizeof(int));
        }
      }
    }
    cout << "^^^\n";

  }
}
