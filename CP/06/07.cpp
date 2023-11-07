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
		     ((0x208222>>c)&1 ? a : b) ++;
			}
		}
		cout << a<<"/"<<b<<"/"<<s.length()<<"\n";
	}
}
