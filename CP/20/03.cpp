#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	string s, buf;
	set<string> sets;
	while(cin >> s) {
		ifstream file(s);
    char c;
    
    while (file.get(c)) {
    	  if(isalpha(c)) {
    	  	 buf+=tolower(c);
    	  } else if(buf.length()) {
    	  	sets.insert(buf);
          buf = "";
    	  }
    }
    if(buf.length())
      sets.insert(buf);
	}
	for(string s2 : sets) {
		 cout << s2 <<"\n";
	}
}
