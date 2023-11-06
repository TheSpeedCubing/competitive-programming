#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	  string s;
	  while (getline(cin,s)) {
   int r = 0, i = 8;
	  	  while(i--) {
	  	  	char c = s[(7-i)*2];
	  	  	r += (c - (c<= '9'?'0':55)) * ((int) pow(16,i));
	  	  }
	  	  cout << r<<"\n";
	  	  }
}