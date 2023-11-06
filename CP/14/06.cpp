#include <iostream>

using namespace std;

	
int main() {
  bool cache[1000001] = {0};
	int T,n,w;
	cin >> T;
	while(T--) {
	cin >> n >> w ;
	
		int max = -2147483648,
		    maxP = 0,
		    lastN = 0,
		    t, 
		    last = 0,
		    i = 0;
		for (;i<n;i++) {
			cin >> t;
			
			if(i>0)
				 cache[i-1] = ((last < 0 && t > 0) || (last > 0 && t < 0)); 
			
			last = t;
			if(i>=w-1) {
				  lastN += (cache[i-1] - cache[i-w]);
				  if (lastN > max) {
				 	   max = lastN;
				 	   maxP = i - w + 2;
				  }
			} else {
				lastN += cache[i];
			}
		}
		cout << maxP<<"\n";
	}
}
