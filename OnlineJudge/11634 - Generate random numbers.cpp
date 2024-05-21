#include <bits/stdc++.h>

using namespace std;
int main() {
	int i;
	while(cin >> i && i) {
		set<int> c;
		c.insert(i);
		
		int cnt = 1;
		while(true) {
		   i *= i;
		   string s = to_string(i);
		   while(s.length() < 8) {
		   	  s = '0' + s;
		   }
		   
		   i = stoi(s.substr(2,4));
		   if(c.count(i)) {
		   	  break;
		   }
		   c.insert(i);
		   cnt++;
		}
		cout << cnt <<"\n";
	} 
}
