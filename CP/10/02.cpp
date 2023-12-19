#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c,k,m,l;
	while(cin >> c >> k >> m >> l){
		vector<int> s;
		while(1) {
		  l = (c * l + k)%m;
		  auto t2 = find(s.begin(),s.end(),l);
		  if(t2 != s.end()) {
		  		cout << (s.size() - (t2 - s.begin())) <<"\n";
		  		break;
		  }
		  s.push_back(l);
		}
	}
}
