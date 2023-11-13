#include <iostream>

using namespace std;

int main()
{
	long long n;
	while(cin >> n){
		  long long j = 1, flag = 1;
		  while(j * j <= n && flag) {
		  	flag = !(!(n % j) && 2*j *j >= n);
		  	j++;
		  }
       cout << (flag ? "No\n" : "Yes\n");
	}
}
