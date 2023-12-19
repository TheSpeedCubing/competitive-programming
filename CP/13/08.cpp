#include <bits/stdc++.h>
using namespace std;

int arr[13],dt[13];
void pr(int start, int end, int index) {
    if (index == 6) {
        for (int i = 0; i < 6; i++)
            cout << dt[i] << (i == 5 ?"\n": " ");
    } else 
      for (int i = start; i <= end && end - i + 1 >= 6 - index; i++) {
        dt[index] = arr[i];
        pr(i + 1, end, index + 1);
    }
}

int main()
{
	int n, flag = 1;
	while(cin >> n && n){
		if(flag)
		  flag =  0;
		else cout <<"\n";
		int d, i = 0;
		for(;i<n;i++){
		  cin >> d;
		  arr[i] = d;
		}
		sort(arr,arr+n);
		pr(0,n-1,0);
	}
}

