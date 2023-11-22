#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long n;
	while(cin >> n){
		string s2 = to_string(max(-n,n));
		int rev = n < 0, l = s2.length(), i = 0;
		
		if(rev)
		  cout <<"(";
		
		while(i < l) {
			
			cout << s2[i++];
			
			if(s2[i] && !((l - i) % 3))
				cout << ",";
		
		}
	  cout << (rev ? ")\n" : "\n");
	}
}
