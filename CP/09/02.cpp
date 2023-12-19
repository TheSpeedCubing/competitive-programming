#include <bits/stdc++.h>

using namespace std;

int n,m,c,i;

int J(int n,int i) {
	return (i == 1 ? (m-1+n) : J(n-1,i-1)+m)
	% n;
}
int main()
{
    while(cin >> n >> m >> c) {
      set<int> arr;
      i = -c + 1;
      while(i<1)
    	  arr.insert(J(n,n+ i++));
      
      i = 0;
      for(int d : arr) {
      	 cout << (i++ ? " ":"") << d+1;
      }
      cout <<"\n";
    }
}
