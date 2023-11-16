#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
	int c;
	while(cin >> c) {
		 string s; 
		 long long i = 0;
		 if(c == 1) {
		 	  cin >> i;
		 	  cin.ignore();
        while (i) {
            s = (char) (i % 16 + 65) + s;
            i >>= 4;
        }
        cout << s <<"\n";
		 } else {
		 	 cin >> s;
		 	 for(char c : s){
		 	 	  i += c-'A';
		 	 	  i*=16;
		 	 }
       cout << i/16 <<"\n";
		 }
	}
}
