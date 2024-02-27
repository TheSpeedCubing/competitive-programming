#include <bits/stdc++.h>
using namespace std;

int main()
{
	string ans,sc,min,in;
	getline(cin, ans);
	getline(cin, sc);
	getline(cin, min);
	int c;
	scanf("%d ",&c);
	while(c--){
	  getline(cin, in);
   	int score=0, tt=0, i=in.length();
   	while(i--) {
   		if(in[i] != ' ') {
   		  tt += sc[i] - 48;
   		  score += in[i] == ans[i] ? sc[i] - 48 : (in[i] !='.' ? 48-min[i] : 0);
   	  }
   	}
   	int r = ceil(100.0 * score / tt);
   	cout << (r >= 0 ? r : 0) <<"\n";
	}
}
