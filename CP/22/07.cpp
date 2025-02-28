#include <bits/stdc++.h>

using namespace std;

int main() {
	int t , i;
	string s;
	cin >> t;
	deque<int> v;
	while(t--) {
	   cin >> s;
	   if(s == "push_front") {
	     cin >> i;
	     v.push_front(i);
	   }
	   if(s == "push_back") {
	     cin >> i;
	     v.push_back(i);
	   }
	   if(s == "front") {
	   	if(v.size()) {
	      cout <<v.front() <<"\n";
	      v.pop_front();
	   	} else cout <<"No job!\n";
	   }
	   if(s == "back") {
	   	if(v.size()) {
	      cout <<v.back() <<"\n";
	      v.pop_back();
	   	} else cout <<"No job!\n";
	   }
	   if(s == "reverse")
	     reverse(v.begin(),v.end());
	}
}
