#include <iostream>
using namespace std;

int main() {
    char c;
    int m, a, b, ct, cp;
    while(cin>>c>>m>>a>>b){
    	  ct = b < 0 ? -b : b;
        cp = (a < 0 ? (m - (-a % m)) : a) % m;
        while(ct--){
            cout << (char) ((c - 97 + cp) % 26 + 97);
            cp = (cp + (b < 0 ? m - 1 :1)) % m;
        }
        cout <<"\n";
    }
}