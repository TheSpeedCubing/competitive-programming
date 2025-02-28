#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long SuperLarge;

int main() {
	
	SuperLarge n,q,u;
	string s;
	
	cin >> n >> q;
	
	while(q--) {
		cin >> u >> s;
		
		SuperLarge k = (n+1)/2, incLimit = k;
		while(u % k) {
			k /= 2;
		}
		
		for(char c : s) {
			if(c == 'U') {
				if(k < incLimit) {
					 u += k;
				   k *= 2;
					 if(!(u%(k*2)))
					   u -= k;
				}
			} else if(k / 2) {
				 k /= 2;
				 u += (c == 'L' ? -k : k);
			}
		}
		
		cout << u <<"\n";
	}
}

