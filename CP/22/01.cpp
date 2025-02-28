#include <bits/stdc++.h>

using namespace std;

map<int,deque<int>> arr;
map<int,int> location;

int main() {
	int n,m,t,a,b;
	cin >> n >> m;
	
	
	for(int i = 1;i<=n;i++) {
		arr[i].push_back(i);
		location[i] = i;
	}
  while(m--) {
  	 cin >> t >> a >> b;
  	 if(t) {
  	 	  for(int i : arr[a]) {
  	 	  	 arr[b].push_back(i);
  	 	  	 location[i] = b;
  	 	  }
  	 	  arr[a].clear();
     } else {
  	  	arr[location[a]].erase(remove(arr[location[a]].begin(),arr[location[a]].end(),a),arr[location[a]].end());
  	  	auto it = find(arr[location[b]].begin(), arr[location[b]].end(), b);
     	  arr[location[b]].insert(it+1,a);
        location[a] = location[b];
     }
  }
  
  for(int i = 1;i<=n;i++) {
  	cout << "#"<<i<<":";
  	 for(int j : arr[i]) {
  	 	 cout << " "<<j;
  	 }
  	 cout <<"\n";
  }
}
