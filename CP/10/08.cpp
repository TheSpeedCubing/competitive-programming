#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while(getline(cin,s)){
		 int a=0,b=0;
		 for(char c : s) {
		 	  a+= "sun"[a] == tolower(c);
		 	  b+= "cloud"[b] == tolower(c);
		 }
		 cout << (a==3 && b == 5? "Success\n" : "Fail\n");
	}
}
