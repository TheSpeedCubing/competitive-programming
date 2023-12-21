#include <bits/stdc++.h>

using namespace std;


struct sorting {
  bool operator()(string a, string b) {
    int l1 = a.length(), l2 = b.length();
    return l1 == l2 ? a < b : l1 < l2;
  }
};

int main() {
	set<string,sorting> s;
	string str;
	char c;
	while(cin.get(c)) {
	  if(isalpha(c))
	    str+=tolower(c);
	 	else {
	 		if(str != "")
	 			s.insert(str);
	 		str = "";
	 	}
	}
	 
	for(string str : s)
	  cout << str <<"\n";
}

