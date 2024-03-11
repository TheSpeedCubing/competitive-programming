#include <bits/stdc++.h>

using namespace std;

map<string,set<int>> m;
string s;
int line = 1;

void check() {
			if(s.length()) {
			  m[s].insert(line);
			}
}
int main() {
	char c;
	while(cin.get(c)){
		if(isalpha(c)) {
			s += tolower(c);
		} else {
			check();
			s = "";
			if(c == '\n') {
			  line++;
			}
		}
	}
	check();
	for(const auto &p : m) {
		cout << p.first <<"\n    ";
		int print = 0;
		for(int i : p.second) {
		   cout << (print++ ? ",":"") << i; 
		}
		cout <<"\n";
	}
}

