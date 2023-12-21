#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int flag = 0;
	while(getline(cin,s)) {
		if(flag++)
		  cout << "\n";
		string s2;
		while(getline(cin,s2) && s2 != "^^^") {
			cout << (s.find(s2) == string::npos ? "no\n" : "yes\n");
		}
	}
}
