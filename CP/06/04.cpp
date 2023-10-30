#include <iostream>
using namespace std;

int main() {
    string n,m;
    while (cin >> n >> m) {
        int c[256] = {0}, count = 0, i=0,j=0;
        while(n[i]) {
            count++;
            if (n[i] != n[i+1]) {
                if (c[n[i]] < count)
                    c[n[i]] = count;
                count = 0;
            }
            i++;
        }
        while(m[j]) {
        	cout << c[m[j]] << (m[j+1]?" ":"\n");
            j++;
        }
    }
}