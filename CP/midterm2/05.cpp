#include <iostream>
using namespace std;

int main()
{
	long long n;
	while(cin >> n){
		string s;
		while(n){
			s = (char) (n % 16 + 'A') + s;
			n >>= 4;
		}
		cout << s <<"\n";
	}
}
