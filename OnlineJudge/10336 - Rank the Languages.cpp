#include <iostream>

using namespace std;

string map[1024];
bool visited[1024][1024];
int result[128];
int H,W;
char current;

void DFS(int,int);

void canDFS(int i,int j) {
	if(i >= 0 && j >= 0 && i < H && j < W) {
	  if(!visited[i][j] && current == map[i][j]) {
	    DFS(i,j);
	  }
	}
}

void DFS(int i,int j){
	visited[i][j] = 1;
  canDFS(i-1,j);
  canDFS(i+1,j);
  canDFS(i,j-1);
  canDFS(i,j+1);
}

int main() {
  int T;
  cin >> T;
  for(int world = 1;world<=T;world++){
  	cin >> H >> W;
  	
  	for(int i = 0;i<H;i++) {
  		for(int j = 0;j<W;j++){
  	    visited[i][j] = 0;  	
  	  }
  	}
  	
  	for(int i = 0;i<128;i++) {
  		result[i] = 0;
  	}
  	
  	for(int i = 0;i<H;i++)
  	 cin >> map[i];
  	
  	for(int i = 0;i<H;i++) {
  		 for(int j = 0;j<W;j++){
  	     if(!visited[i][j]) {
  	     	 current = map[i][j];
  	       DFS(i,j);
  	       result[current]++;
  	     }
  	  }
  	}
  	
      cout <<"World #"<< world<<"\n";
      for( int j = H * W ; j >= 1 ; j--)
        for( int k = 'a' ; k <= 'z' ; k++ )
          if(result[k] == j)
            printf( "%c: %d\n", k, j );
  }
}
