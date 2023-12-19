#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while(getline(cin,s, ',')){
       	cout << s <<" ";
		    cin.ignore(1024,',');
		    cin.ignore(1024,',');
        int a, t=5;
        while(t--) {
        	  cin >> a;
            cout << "FFFFFFDCBAA"[a/10] << (t ? "":"\n");
	      		cin.ignore(1024, t ? ',' : '\n');
        }
    }
}
