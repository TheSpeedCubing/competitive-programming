// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

typedef long long lll;
using namespace std;

int main() {
    int d;
    while(cin >> d){
        int s[d];
        for(int i = 0;i<d;i++) {
          int in;
          cin >> in;
          s[i] = in;
        }

    lll buff = 1024;
    lll    f[buff] = {1};

    for(int mm : s) {
      lll g[buff] = {-mm,1} , r[buff] = {0};
      lll i = buff;
      while(i--) {
          lll j = buff;
          while(j--)
                 r[i+j] += g[i] * f[j];
      }
      memcpy(f,r,sizeof(f));
    }

      int found = 0,firstp = 1;
      int n = buff-1;
      while(n--) {
      	found = found || f[n];
          if(found) {
          	  int printN = 0;
                if(f[n] == 1) {
                	if(!firstp)
                    cout <<" + ";
                } else if(f[n]==0) {
                	if(n == 0)
                	   cout << " + ";
                } else if(f[n] > 0) {
                	printN = 1;
                	cout << " + ";
                } else if(f[n] == -1) {
                	cout << " - ";
                }else if(f[n] <0) {
                	printN = 1;
                	cout << " - ";
                }
                if(n == 0 || printN)
                  cout << to_string(abs(f[n]));
                if(f[n])
                cout <<(n == 1 ? "x" : (n==0?"":("x^"+to_string(n))));
               firstp=0;
          }
      }
      cout <<" = 0\n";
    }
}
