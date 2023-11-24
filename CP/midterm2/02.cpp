#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long n[3];
	while(cin >> n[0] >> n[1] >>n[2]){
		sort(n,n+3);
		int a = n[0] * n[0];
		int b = n[1] * n[1];
		int c = n[2] * n[2];
		if(n[0]+n[1]<=n[2])
		  cout <<"No\n";
		else if(a+b<c)
		  cout <<"Obtuse\n";
		else if(a+b>c)
		  cout <<"Acute\n";
		  else
		  cout <<"Right\n";
	}
   // Put your code below

    return 0;
}
