#include <bits/stdc++.h>

using namespace std;


int dp[1024][1024];
int m[1024][1024];

int add(int i,int j,int yOFF) {
	  if(m[i-1][j + yOFF] == 'B'){
	    if(i != 1)
	      return dp[i-2][j+yOFF*2];
	    return 0;
	  } else return dp[i-1][j+yOFF];
}

int main(){
	int T;
	cin >> T;
		for(int t = 1;t<=T;t++){
		
		int size;
		cin >> size;
		
		char c;
		
		for(int i = 0;i<size;i++) {
		  memset(dp[i], 0, 1024 * sizeof(int));
		  for(int j = 0;j<size;j++) {
		  	 cin >> c;
		  	 m[i][j] = c;
		  	 
		  	 if(c == '.')
		  	   dp[i][j] = (i == 0);
		  	 else
		  	   dp[i][j] = 0;
		   }
		  cin.ignore();
		}
		
		
		for(int i = 1;i<size;i++) {
			
			int breakthis = 0;
			
		  for(int j = 0;j<size;j++) {
		  	 char c = m[i][j];
		  	 if(c == 'B')
		  	   dp[i][j] = 0;
		  	 else {
	         if (j < size) 
		         dp[i][j]  += add(i,j,1);
           if(j > -1)
		         dp[i][j]  += add(i,j,-1);
		  	 }
         dp[i][j] %= 1000007;
		  	 	  if(c == 'W') {
		  	 	    cout << "Case "<< t <<": "<< dp[i][j] << "\n";
		  	 	    breakthis = 1;
		  	 	    break;
		  	 	  }
		  }
		  
		  if(breakthis)
		  	 break;
		}
	}
}
