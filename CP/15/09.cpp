#include <bits/stdc++.h>

using namespace std;

int main() {
	int T,flag=0,Q,l,r;
	cin >> T;
	while(T--){
		if(flag++)
		  cout <<"\n";
		int m,n;
		cin >> m >> n;
		int arr[m][n];
		for(int i = 0;i<m;i++) {
		  for(int j = 0;j<n;j++) {
			   cin >> arr[i][j];
		  }
		}
		
		pair<int,int> result[32768];

    int turn = 0
       ,x = 0, y = 0, x1 = 0, y1 = 0, x2 = n - 1, y2 = m - 1
       ,i=1;
      while(i <= m * n) {
        result[i] = make_pair(y,x);
        turn ? (turn == 1 ? y++ : (turn == 2 ? x-- : y--)) : x++;

      if (x == x2) {
        if (y == y1 && turn == 0) {
        	turn++;
          y1++;
        }
        if (y == y2 && turn == 1) {
        	turn++;
          x2--;
        }
      }
      if (x == x1) {
        if (y == y2 && turn == 2) {
        	turn++;
          y2--;
        }
        if (y == y1 && turn == 3) {
          turn = 0;
          x1++;
        }
      }
      i++;
      }
      
		cin >> Q;
		while(Q--) {
			cin >> l >> r;
			int sum = 0;
			while(l <= r){
				sum+= arr[result[l].first][result[l].second];
				l++;
			}
			cout << sum <<"\n";
		}
	}
}
