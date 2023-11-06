#include <iostream>
using namespace std;

int main()
{
	string s;
	while(cin >>s && s != "0"){
		for(int i = 0;i<s.length();i++){
			cout <<s[i]<<(i==s.length()-1?"\n":" ");
		}
		
		
	}
}
