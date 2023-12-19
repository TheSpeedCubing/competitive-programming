#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        double y = 1;
        while (n--)
            y *= n + 1;
       cout << to_string(y)[0] <<"\n";
    }
}
