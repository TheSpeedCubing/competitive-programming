#include <bits/stdc++.h>

using namespace std;
int main()
{
	int f[1024] = {};
	
	for(int i = 0;i<1024;i++){
		for(int j = 1;j<=i;j++){
			if(i%j == 0)
			  f[i]+=j;
		}
	}
	int n;
	int c = 1;
	while(cin >> n && n) {
		int pos = -1;
		for(int i = 1023;i>=0;i--){
			 if(f[i] == n) {
			 	pos = i;
			 	break;
			 }
		}
		cout << "Case "<<c<<": "<<pos<<"\n";
		c++;
	}
}
