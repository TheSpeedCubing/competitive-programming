#include <bits/stdc++.h>

using namespace std;
int main() {
    int a, b;
    while(cin >> a >> b && (a || b)) {
        int r = 1;
        int count = 0;
        while(r*r <= b) {
            if(a <= r*r)
              count++;
            r++;
        }
        cout << count <<"\n";
    }
}
