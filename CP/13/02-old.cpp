#include <iostream>

using namespace std;

int main()
{

	   long long n,
	             dp[10001] = {1,1}, 
	             i = 2;
	   while(i < 10001){
	   	 int j = 0;
	   	 while(j<i) {
	   	 	 dp[i] += dp[j] * dp[i - j - 1];
	   	 	 dp[i] %= 1000000007;
	   	 	 j++;
	   	 }
	   	 i++;
	   }
	while(cin >> n)
	   cout << dp[n]<<"\n";
}
