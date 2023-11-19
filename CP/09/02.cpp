#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,c,i;

int J(int n,int i) {
	return (i == 1 ? (m-1+n) : J(n-1,i-1)+m)
	% n;
}
int main()
{
    while(cin >> n >> m >> c) {
      vector<int> arr;
      i = -c + 1;
      while(i<1)
    	  arr.push_back(J(n,n+ i++));
    	  
      sort(arr.begin(), arr.end());
      
      i = 0;
      while(i<c)
        cout << arr.at(i)+1 << ((i++==c-1) ? "\n":" ");
    }
}
