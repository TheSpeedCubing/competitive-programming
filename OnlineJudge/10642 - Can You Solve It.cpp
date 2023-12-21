#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long T;
	cin >> T;
	for(int t=1;t<=T;t++) {
		int a,b,c,d;
		cin >>a>>b>>c>>d;
		long long l = c+d+1;
		long long l2 = a+b+1;
		cout << "Case "<<t<<": "<< 
		(l * (l+1) / 2 - d) - 
		(l2 * (l2+1) / 2 - b) 
		<<"\n";
	}
}
