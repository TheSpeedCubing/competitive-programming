#include <iostream>
#include <string>
using namespace std;

int v[1024], z = 1023, i, b;
int main() {
    string n;
    while (getline(cin,n)) {
        for (i = 0; i < z; i++) {
            if (i < n.length())
                v[i] += n[n.length() - i - 1] - 48;
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
    }
    while (z--) {
        if (v[z])
            b = 1;
        if(b)  
        cout << v[z];
    }
    cout <<"\n";
}