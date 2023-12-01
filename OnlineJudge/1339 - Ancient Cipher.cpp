#include <bits/stdc++.h>

using namespace std;


int main() {
	string s1,s2;
	while(cin >> s1 >> s2){
		int c1[26] = {}, c2[26] = {};
		
		for(int i = 0;i<s1.length();i++) {
			 c1[s1[i] - 'A']++;
			 c2[s2[i] - 'A']++;
		}
		
		sort(c1,c1+26);
		sort(c2,c2+26);
		bool flag = true;
		for(int i = 0 ;i<26;i++){
			 if(c1[i] != c2[i])
			   flag = false;
		}
		cout << (flag ?"YES\n":"NO\n");
	}
}
