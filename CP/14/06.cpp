#include <iostream>

using namespace std;

	
int main() {
  bool cache[1000001] = {0};
	int T;
	cin >> T;
	while(T--){
	int n,w;
	cin >> n >> w ;
		int max = -2147483648;
		int maxP = 0;
		int lastN = 0,firstN = 0;
		int t = 0, last = 0;
		for (int i = 0;i<n;i++) {
			cin >> t;
			if(i>0) {
				 int s1 = last;
				 int s2 = t;
				 cache[i-1] = ((s1 < 0 && s2 > 0) || (s1 > 0 && s2 < 0)); 
			}
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
