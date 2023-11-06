#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--) {
		int t = 4096,
		i = t,
		flag = 0,
		firstp = 1,
		test,
		f[t] = {0} ,
		g[t] = {0} , 
		r[t] = {0};
		
	  while(cin >> test && test != -1)
	  	  cin >> f[test];
	  while(cin >> test && test != -1)
	  	  cin >> g[test];
	  
	  while(i--) {
	  	int j = t;
	  	while(j--)
	  	 	  r[i+j] += g[i] * f[j];
	  }
	  
	  t--;
	  while(t--) {
	  	if(r[t])
	  		flag = 1;
	  	if(flag && r[t] || !(t||flag) ){
	  	 	 cout <<(firstp?"":" ")<< t<<" "<<r[t];
	  		 firstp=0;
	  	}
	  }
	  cout <<"\n";
	}
	
}
