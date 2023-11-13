#include <iostream>
#include <cstdio>

using namespace std;

int isBachelorNum(int n)
{
	n = n < 0 ? -n : n;
	  bool b[128] = {0};
	  {
	  	while(n){
	  		if(b[n%10]){
	  			return 0;
	  		}
	  		 b[n%10] = 1;
	  		 n/=10;
	  	}
	  }
    return 1;
}

int main()
{
	int i;
	while(cin >> i){
		cout << (isBachelorNum(i) ? "Yes\n" : "No\n");
	}
}
