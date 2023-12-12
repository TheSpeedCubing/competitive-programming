#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		
		int arr[n];
		for(int i = 0;i<n;i++){
			cin >> arr[i];
		}
		
		int max = -2147483647;
		int min = arr[n-1];
		for(int i = n - 2;i>=0;i--){
			  int t = arr[i];
			  int r = t - min;
			  if(r > max){
				  max = r;
			  }
			  if(t < min)
			    min = t;
			}
		cout << max <<"\n";
	}
}
