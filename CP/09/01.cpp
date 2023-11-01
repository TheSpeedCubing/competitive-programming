#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	char c;
	while(cin >> c) {
		 cin.ignore();
		 string s = "";
		 if(c == '1'){ 
		 	long long i;
		 	 cin >> i;
		 	 cin.ignore();
        while (i) {
            s = (char) (i % 16 + 65) + s;
            i >>= 4;
        }
        cout << s <<"\n";
		 } else {
		   getline(cin,s);
		   long long result = 0 , t = s.length();
		   while(t--)
		   result += (s[s.length()-t-1] - 'A') * pow(16,t);
           cout << result <<"\n";
		 }
	}
}
