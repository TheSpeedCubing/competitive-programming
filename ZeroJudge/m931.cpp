#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[20];
	int b[20];
	int c[20];
	int d[20];
	for(int i = 0;i<n;i++){
		cin >> a[i] >> b[i];
		c[i] = a[i] * a[i] + b[i] * b[i];
		d[i] = c[i];
	}
	sort(c,c+n);
	for(int i = 0;i<n;i++){
		if(d[i] == c[n-2]) {
			cout << a[i] <<" "<<b[i]<<"\n";
	    break;
		}
	}
}
