#include <iostream>

using namespace std;

int main() {
  
  int T;
	cin >> T;
  
	while(T--) {
		 int N;
		 cin >> N;
		 int arr[N];
		 for(int i = 0;i<N;i++)
		   cin >> arr[i];
		 
		 int cnt = 0;
		 for(int i = 0;i<N-1;i++){
		 	 if(cnt % 2) {
		 	 	  if(arr[i] < arr[i+1])
		 	 	    cnt++;
		 	 } else {
		 	 	  if(arr[i] > arr[i+1])
		 	 	    cnt++;
		 	 }
		 }
		 cout << cnt+1 <<"\n";
	}
}
