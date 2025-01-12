#include <bits/stdc++.h>

using namespace std;

int main() {
  double z,t,s[32768];
  int m,d,flag=1;
  while(cin >> z >> t >> m >> d) {
     if(flag)
       flag=0;
  	 else
  	   cout <<"\n";

  	 double def = 1;
  	 s[0] = 1;
  	 int n = 0;
  	 do {
  	 	  n++;
        def += pow(z,n);
  	 	  s[n] = def;
     } while(abs(def - s[n-1]) >= t);
     int f2 = m <= n;
     for(int i = max(0,n-m+1); i<= n;i++) {
  	 	if(s[i] == 1)
  	 	  f2 = 1;
  	 	if(f2)
  	    cout << fixed << setprecision(d)<< s[i]<<"\n";
  	 }
  }
}
