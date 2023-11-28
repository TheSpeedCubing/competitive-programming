#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int arr[N];
		for(int i = 0;i<N;i++){
			cin >> arr[i];
		}
		sort(arr,arr+N);
		
		int mid = N%2 == 0 ? (arr[N/2] + arr[N/2-1])/2 : arr[N/2];
		int sum = 0;
		for(int i : arr){
			sum += abs(i - mid);
		}
		cout << sum <<"\n";
	}
}
