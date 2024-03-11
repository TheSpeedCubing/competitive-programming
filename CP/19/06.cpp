#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N, M, K;
	cin >> T;
	while(T--) {
		cin >> N >> M;
		vector<int> v;
		set<int> leave;
		
		while(M--) {
			cin >> K;
			leave.insert(K);
		}
		
		int i = 1, result[3] = {};
		while(i<=pow(2,N)) {
			int k = 0,r=2;
			while(r--)
			  k += !(leave.count(i++));
			v.push_back(k);
		}
		
		while(v.size()) {
			 vector<int> v2;
			 int f, i = 0;
			 for(int k : v) {
			 	  result[k]++;
			 	  if((i++)%2)
			 	      v2.push_back((bool) f + (bool) k);
			 	  else
			 	      f = k;
			 }
			 v = v2;
		}
		
		i = 3;
		while(i--) {
			cout << result[i] << (i ?" ":"\n");
		}
	}
}

