#include <bits/stdc++.h>

using namespace std;

int T, n,a, t;

int main() {
	cin >> T;
	while(t<T) {
		 cout << "Case #"<<++t<<":\n";
		 set<int> s[4],diff[4];
		 map<int,set<int>> m;
		 
		 int i = 1;
		 
		 while(i<=3) {
		 	 cin >> n;
		 	 while(n--) {
		 	 	  cin >> a;
		 	 	  s[i].insert(a);
		 	 	  m[a].insert(i);
		 	 }
		 	 i++;
		 }
		 
		 i = 0;
		 
		 size_t maxSize = 0;
		 while(i<=3) {
		 	 for(int a : s[i]) {
		 	 	 if(m[a].count(i) && m[a].size()==1) {
		 	 	 	  diff[i].insert(a);
		 	 	 }
		 	 }
		 	 maxSize = max(diff[i].size(),maxSize);
		   i++;
		 }
		
		 i = 0;
		 
		 while(i<=3) {
		 	if(diff[i].size() == maxSize) {
		     cout << i <<" "<< maxSize;
		     for(int j : diff[i])
		       cout << " "<<j;
		     cout <<"\n";
		 	}
		 	i++;
		 }
	}
}
