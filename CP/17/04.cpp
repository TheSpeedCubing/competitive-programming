#include <bits/stdc++.h>

using namespace std;

int main() {
  int T,x,n,m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    
    int island[100000], i = m;

    while(i--) {
      cin >> island[i];
      island[i]*=10;
    }
    
    sort(island, island+m);

    int left = 0, right = (island[m - 1] - island[0]) / (n + 1);
    
    while (left <= right) {
    	int mid = (left + right) / 2,
    	    shop = 1, i=1, r= island[0] + mid;
    	    
      while(i< m && shop<=n) {
        if(abs(island[i]-r) > mid){
          shop++;
          r = island[i] + mid;
        }
        i++;
      }
      
      shop > n ? left = mid + 1 : right = mid - 1;
  }
    cout << left/ 10 << "." << left % 10 << "\n";
  }
}
