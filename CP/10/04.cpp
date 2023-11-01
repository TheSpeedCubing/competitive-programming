#include <iostream>
#include <string>

using namespace std;
int main()
{
   string s;
   while(getline(cin,s)){
   	string s2;
   	for(int i = s.length()-1;i>-1;i--)
   		 	s2 = s2.length() ?s2.substr(s2.length()-1) + s[i] + s2.substr(0,s2.length()-1) : s2+s[i];
   	cout << s2 <<"\n";
  }
}
