#include <bits/stdc++.h>

using namespace std;
int main()
{
		
	string s1 = "edcrfvtgbyhnujmik,ol.p;['] ";
	string s2 = "qazwsxedcrfvtgbyhnujmikolp ";
		
	string s;
	while(getline(cin,s)){
		for(char c : s) {
			cout << s2[s1.find(tolower(c))];
		}
		cout <<"\n";
	}
}
