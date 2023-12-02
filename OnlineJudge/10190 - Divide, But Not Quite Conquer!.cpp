#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;
	while(cin >> a >> b) {
		if(b == 0 || b == 1 || a < b) {
		  cout <<"Boring!\n";
		  continue;
		}
		string s = to_string(a);
		while(1) {
			if(a%b != 0) {
				cout << "Boring!\n";
				break;
			}
			if(a == b && a % b == 0) {
	    	cout << s <<" 1\n";
	      break;
			}
			a/=b;
			s += " " + to_string(a);
		}
	}
}
