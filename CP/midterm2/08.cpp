#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int t = 25;
	while(t--){
		cin >> n;
		if(t % 5 == 0)
		  printf("%2d\n",n);
    else 
		  printf("%2d ",n);
	}
	  return 0;
}
