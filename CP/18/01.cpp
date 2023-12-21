#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int flag = 0;
	while(getline(cin,s)) {
    if(flag++)
      cout <<"\n";
		string r, num , str;
		for(char c : s) {
			if(isalpha(c)) {
			 r += tolower(c);
			 str += tolower(c);
			}
			if(isdigit(c)) {
			 r += c;
			 num += tolower(c);
			}
		}
    string num2 = num, num3 = num, str2 = str,str3 = str;
    sort(num2.begin(), num2.end());
    sort(num3.begin(), num3.end(),greater<char>());
    sort(str2.begin(), str2.end());
    sort(str3.begin(), str3.end(),greater<char>());
		cout << r <<"\n"
		<< num << str <<"\n" 
		<< str <<num<<"\n"
		<<num2<<str2<<"\n"
		<<num3<<str3<<"\n"
		<<num3<<str2<<"\n"
		<<num2<<str<<"\n"
		<<str2<<num<<"\n";
	}
}