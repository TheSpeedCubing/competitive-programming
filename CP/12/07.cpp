#include <iostream>
#include <string>
using namespace std;


void showBusinessNum(long long n){
		bool rev = n < 0;
		string s2 = to_string(rev ? -n : n);
		int l = s2.length();
		string s;
		for(int i = 0;i<l;i++){
			s += s2[i];
			if(((i + 1 - l%3) % 3) == 0 && i != l-1)
				s+=",";
		}
	cout << (rev ?"(":"") << s<< (rev ?")":"")<<"\n";
}
int main()
{
	long long n;
	while(cin >> n){
	   showBusinessNum(n);
	}
}
