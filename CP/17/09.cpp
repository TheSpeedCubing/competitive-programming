#include <bits/stdc++.h>

using namespace std;

int vec[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

int main() {
	int m,n,i,j;
	while(cin >> m >> n >> i >> j) {
		 char arr[m][n];
		 fill(&arr[0][0],&arr[0][0] + m * n , 0);
		 string in, s = "A";
		 arr[i][j] = 'A';
		 cin >> in;
		 int k = 1;
		 for(char c : in) {
		 	  c = c - '1';
		 	  int x = i + vec[c][0], y = j + vec[c][1];
		 	  if(x >= 0 && x < m && y >= 0 && y < n) {
		 	  	 if(!arr[x][y]) {
		 	  	    i = x;
		 	  	    j = y;
		 	  	    c = (k % 26 + 'A');
		 	  	 	  arr[i][j] = c;
		 	  	 	  s += c;
		 	  	 }
		 	  }
		 	  k++;
		 }
		 cout << s <<"\n";
	}
}
