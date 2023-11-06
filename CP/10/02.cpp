#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int c,k,m,l;
	while(cin >> c >> k >> m >> l){
		int cp = l;
		vector<int> s;
		while(1) {
		  l = (c * l + k)%m;
		  auto t2 = find(s.begin(),s.end(),l);
		  int t = t2 != s.end();
		  if(cp == l || t) {
		  		cout <<(s.size() - (t ? t2-s.begin():-1)) <<"\n";
		  		break;
		  }
		  s.push_back(l);
		}
	}
}
