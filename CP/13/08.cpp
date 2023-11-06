#include <iostream>
#include <algorithm>
using namespace std;

void pr(int arr[], int data[], int start, int end, int index) {
    if (index == 6) {
        for (int i = 0; i < 6; i++)
            cout << data[i] << (i == 5 ?"\n": " ");
    } else 
      for (int i = start; i <= end && end - i + 1 >= 6 - index; i++) {
        data[index] = arr[i];
        pr(arr, data, i + 1, end, index + 1);
    }
}

int main()
{
	int n, flag = 1;
	while(cin >> n && n){
		if(flag)
		  flag =  0;
		else cout <<"\n";
		int arr[n], d , data[n], i = 0;
		for(;i<n;i++){
		  cin >> d;
		  arr[i] = d;
		}
		sort(arr,arr+n);
		pr(arr,data,0,n-1,0);
	}
}

