#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int J(int n,int m,int i) {
	return (i == 1 ? (m-1+n) : J(n-1,m,i-1)+m)
	% n;
}
int main()
{
    int n,m,c;
    while(cin >> n >> m >> c) {
      vector<int> arr;
      int i = n-c+1;
      for(;i<=n;i++)
    	  arr.push_back(J(n,m,i)+1);
    	  
      sort(arr.begin(), arr.end());
      for (i = 0; i < c; i++)
        cout << arr.at(i) << ((i==c-1) ? "\n":" ");
  }
}
