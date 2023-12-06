#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--) {
		int m,y,c;
		cin >>m>>y>>c;
		
		string s;
		cin >> s;
		bool f = 1;
		for(char i : s){
			if(i == 'M' || i == 'R' || i == 'V' || i == 'B')
			  m--;
			if(i == 'Y' || i == 'R' || i == 'G' || i == 'B')
			  y--;
			if(i == 'C' || i == 'G' || i == 'V' || i == 'B')
			  c--;
			if(m<0||y<0||c<0){
		    f = 0;
		    cout<<"NO\n";
		    break;
			}
		}
		if(f)
		cout<<"YES "<<m<<" "<<y<<" "<<c<<"\n";
	}
}
