#include <bits/stdc++.h>

using namespace std;
int main()
{
	int i,j;
	while(cin >> i >> j && i){
		 int r[i] = {0};
		 while(j--) {
		 	 for(int k = 0 ;k<i;k++){
		 		 int in;
		 		 cin >> in;
		 		 r[k] += in;
		 	 }
		 }
		 
		 int max = -1;
		 int maxI;
		 for(int k = 0;k<i;k++){
		 	  if(max <= r[k])  {
		 	  	 max = r[k];
		 	     maxI = k+1;
		 	  }
		 }
		 cout << maxI<<"\n";
	}
}
