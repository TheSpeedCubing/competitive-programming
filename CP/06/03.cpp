#include <iostream>

using namespace std;

int count[256], t , a[6] = { 7, 5, 1, 3, 2, 2}, i,l;

int main() {
    char in;
    while (1) {
        cin >> in;
        if (in == '*' || in == '#') {
            cin >> in >> in;
            t = 2147483647, i = 6;
            while (i--) {
                l = count["peinal"[i]] / a[i];
                if (t > l)
                    t = l;
            }
            cout << t << "\n";

            if (in == '#')
                exit(0);
            i = 256;
            while (i--)
                count[i] = 0;
        }
        count[tolower(in)]++;
    }
}