#include <string>
#include <iostream>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		int a = 0, b = 0, c, i = 0;
		for (; i<s.length(); i++){
			c = tolower(s[i]);
			if (islower(c)) {
		        if (c == 'a' || c=='e'||c=='i'||c=='o'||c=='u')
				    a+=1;
				else b+=1;
			}
		}
		cout << a<<"/"<<b<<"/"<<s.length()<<"\n";
	}
}