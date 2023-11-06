#include <iostream>
using namespace std;

int main()
{
	int n;
	
	while(cin >> n && n){
		
		 int a[n], k = n, i = 0, cnt = 0;
		 
		 for(;i<n;i++)
		 	  cin >> a[i];
		 	  
		 while(k--)
		 	  for(int j = k+1;j<n;j++)
		 	  	if(a[k] > a[j])
		 	  		  cnt++;
		 	  		  
		 cout << cnt<<"\n";
	}
}
