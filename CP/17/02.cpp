#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while(getline(cin,s)){
		s+=" ";
		int i = 0, 
		maxStr = 0,
		words =0,
		upper = 0,
		lower = 0,
		digitCnt = 0,
		weirdCnt = -1,
		existChar = 26,
		existDigit = 10,
		r = 0;
		int g[128] = {0};
		for(char c : s) {
			if(isalpha(c)) {
				existChar -= !g[tolower(c)];
				isupper(c) ? upper++ : lower++;
			}
			else if(isdigit(c)) {
				existDigit -= !g[tolower(c)];
				digitCnt++;
			} else weirdCnt++;
			g[tolower(c)]++;
			if(c != ' ') {
			  i++;
			} else {
				words++;
				maxStr = max(maxStr,i);
			  i = 0;
			}
		}
		for(int i = 'a';i<='z';i++) {
			if(g[i] * 10 > upper+lower)
			  r++;
		}
		cout 
		<< words
		<<" "<<maxStr
		<<" "<<(upper+lower)
		<<" "<<digitCnt
		<<" "<<weirdCnt
		<<" "<<upper
		<<" "<<lower
		<<" "<<existChar
		<<" "<<existDigit
		<<" "<<r<<"\n";
	}
}
