#include <bits/stdc++.h>


using namespace std;

typedef unsigned long long LL;
int main()
{
	int T = 0;
	LL v1,d1,v2,d2;
	while(cin >> v1 >> d1 >> v2 >> d2 && d1) {
		T++;
		cout << "Case #"<<T<<": ";
		if(d1 * v2 < d2 * v1){
			cout << "You owe me a beer!\n";
		} else cout << "No beer for the captain.\n";
		cout << "Avg. arrival time: ";
		LL up =  v1 * d2 + v2 * d1;
		LL down = 2 * v1 * v2;
		if(up % down == 0)
		  cout << up/down;
		else {
		  LL g = __gcd(up,down);
      cout << up/g <<"/"<<down/g;
		}	
		cout <<"\n";
	}
}
