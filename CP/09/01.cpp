#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	char c;
	while(cin >> c) {
		 cin.ignore();
		 string s; 
		 long long i = 0;
		 if(c == '1'){
		 	 cin >> i;
		 	 cin.ignore();
        while (i) {
            s = (char) (i % 16 + 65) + s;
            i >>= 4;
        }
        cout << s <<"\n";
		 } else {
		   getline(cin,s);
		   int t = s.length();
		   while(t--)
		     i += (s[s.length()-t-1] - 'A') * pow(16,t);
       cout << i <<"\n";
		 }
	}
}
