#include <bits/stdc++.h>

using namespace std;

string s[] = {" *"," * *","   *"};

void f(int n, int a) {
	if(n == 1) {
		for(string ss : s) {
			cout << setw(a) << "" << ss <<"\n";
		}
	} else {
		f(n-1,a);
		cout << setw(a) << "";
		int i = pow(2,n);
		while(i--)
		  cout << " *";
		cout <<"\n";
    f(n-1,a+pow(2,n));
	}
}
int main() {
	int n,flag=0;
	while(cin >> n) {
		if(flag++)
      cout <<"\n";
    f(n,0);
	}
}
