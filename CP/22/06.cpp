#include <bits/stdc++.h>

using namespace std;

int main() {
	int t = 1;
	int n, m, k;
	while(cin >> n >> m && n) {
		  cout << "Case " << (t++) << ":\n";
		  vector<int> v;
		  for(int i = 1;i<=min(n,3001);i++){
		  	 v.push_back(i);
		  }
		  char c;
		  while(m--) {
		  	 cin >> c;
		  	 if(c == 'Q') {
		  	 	  int i = v[0];
		  	 	  cout << i <<"\n";
		  	 	  v.erase(v.begin());
		  	 	  v.push_back(i);
		  	 } else {
		  	 	  cin >> k;
		  	 	  auto it = find(v.begin(), v.end(), k);
            if (it != v.end())
               v.erase(it);
            v.insert(v.begin(), k);
		  	 }
		 }
	}
}
