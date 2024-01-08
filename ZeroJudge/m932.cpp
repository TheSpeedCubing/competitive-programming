#include <bits/stdc++.h>

using namespace std;

int vec[6][2] = {{-1,0},{0,1},{1,1},{1,0},{0,-1},{-1,-1}};
int main(){
	int m,n,k;
	cin >> m >> n >> k;
	
	char arr[30][30];
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			 cin >> arr[i][j];
		}
		cin.ignore();
	}
	
	int x = m - 1, y = 0;
	
	int i,j=0;
	
	bool chars[128] = {false};
	
	while(k--) {
		cin >> i;
		int vx =x + vec[i][0];
		int vy =y + vec[i][1];
		
		if(vx >= 0 && vx < m && vy >=0 && vy < n) {
			 x = vx;
			 y = vy;
		}
		if(!chars[arr[x][y]]) {
			 j++;
			 chars[arr[x][y]] = true;
		}
	  cout << arr[x][y];
	}
	cout <<"\n"<<j;
}
