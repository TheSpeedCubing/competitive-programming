#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n[3];
	while(cin >> n[0] >> n[1] >>n[2]){
		sort(n,n+3);
		for(int i = 2;i>=0;i--)
		  cout << n[i] << (i==0?"\n":" ");
	}
   // Put your code below

    return 0;
}
