#include <bits/stdc++.h>

using namespace std;

int h, w, r;

bool verify(int i, int j) {
  return i > -1 && j > -1 && i < h && j < w;
}

bool cp(char c1,char c2){
	if(c1== 'R')
	  return c2 == 'S';
	if(c1=='S')
	  return c2=='P';
	if(c1=='P')
	  return c2=='R';
}

int m[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; 
      
int main() {
	bool flag = 0;
  int T;
  cin >> T;
  while(T--) {
  	if(flag)
  	  cout <<"\n";
  	else flag = 1;
    cin >> h >> w >> r;
    char c1[h][w];

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> c1[i][j];
      }
      cin.ignore();
    }

    while (r--) {
      int c2[h][w];
      fill(c2[0], c2[0] + h * w, 0);
      
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          char c = c1[i][j];
          for(int k = 0;k<4;k++){
              int x = i + m[k][0];
              int y = j + m[k][1];
          	 if(verify(x,y) && cp(c,c1[x][y])){
          	 	 c2[x][y] = c;
          	 }
          }
        }
      }

      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          char c = c2[i][j];
          if(c)
            c1[i][j] = c;
        }
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cout << c1[i][j];
      }
      cout <<"\n";
    }
  }
}
