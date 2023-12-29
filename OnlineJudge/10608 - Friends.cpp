#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t,n,m,a,b;
	cin >> t;
	while(t--){
		cin >> n >> m;
		if(m == 0) {
		  cout << "1\n";
		  continue;
		}
		int maxSize = 0;
	  int team = 0;
	  int arr[30001] = {0};
		int size[30001] = {0};
	
		while(m--) {
			cin >> a >> b;
	    int ta = arr[a];
	    int tb = arr[b];
			if(ta) {
	       	if(tb == 0) {
	       		 arr[b] = ta;
	       		 int k = ++size[ta];
	       		 maxSize = max(maxSize,k);
	       	} else
	       		 if(ta != tb) {
	       		 size[ta] += size[tb];
	       		 for(int i = 0;i<=n;i++)
	       		 	  if(arr[i] == tb)
	       		 	  	 arr[i] = ta;
	       		 maxSize = max(maxSize,size[ta]);
	       	
	       	}
			} else {
				 if(tb) {
				 		 arr[a] = tb;
	       		 int k = ++size[tb];
	       		 maxSize = max(maxSize,k);
				 		 
				 } else {
				 	  //create team
				 	  team++;
				 	  arr[a] = team;
				 	  arr[b] = team;
				 	  size[team] = 2;
	       		maxSize = max(maxSize,2);
				 }
			}
		}
	cout << maxSize <<"\n";
	}
}
