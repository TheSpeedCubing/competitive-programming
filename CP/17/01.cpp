#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while(cin >> n){
		 int arr[32768] = {0}, flag = 1;
		 int i = n * n;
		 while(i--) {
		 	 cin >> arr[i];
		 }
		 i = n * n;
		 while(i--) {
		 	 flag = flag && arr[i] == arr[n*n-i-1];
		 }
		 cout << (flag ?"Yes\n":"No\n");
	}
}
