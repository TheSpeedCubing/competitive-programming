#include <iostream>
using namespace std;

int main()
{
	long long n,l,u;
	while(cin >> n >>l >> u) {
	   long long M = 0, bitshifter=0x80000000;
	   while(bitshifter) {
	   	 M |= (M + bitshifter <= (n & bitshifter ? l : u) ? bitshifter : M);
	   	 bitshifter >>= 1;
	   }
	   cout << M <<"\n";
	}
}
