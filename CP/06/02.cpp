#include <iostream>
using namespace std;

int main() {
    int k,kinvert,t,i;
    char n[1024], c;
    cin >> t;
        while(t--){
            kinvert = i = 0;
            cin >> k >> n;
            while(kinvert * k%37 - 1)
                kinvert++;
            while(c = n[i]){
                c = kinvert *
          	        (c == '+' ? 0:
        	            (c - (c > 64 ? 64 : 21))
        	        ) % 37;
        	       cout << (char) (c ? c + (c > 26 ?21 :64) : '+');
                i++;
            }
        cout <<"\n";
    }
}