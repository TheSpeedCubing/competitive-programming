#include <iostream>
using namespace std;

int main()
{
unsigned	long long n , a , b;
	while(cin >> n >> a >> b){
	unsigned	long long t = 0;
unsigned		long long r = 1;
		while(n) {
			t += (n % 10) * r;
			r *= a;
			n /= 10;
		}
		
		string s;
		while(t){
			s = (char) (t %b + 48) + s;
			t /= b;
		}
		cout << s<<"\n";
	}
}
