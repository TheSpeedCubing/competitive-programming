#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while(getline(cin,s)){
		string s2;
		for(char c : s) {
			if(!isspace(c) && !ispunct(c))
			  s2 += tolower(c);
		}
		int l = s2.length(),i = 0, result = i<l;
		while(i<l) {
			result = result && s2[i] == s2[l-i-1];
		  i++;
		}
		cout << "\"" << s <<"\" is " <<(result?"":"not ") << "a palindrome.\n";
	}
}