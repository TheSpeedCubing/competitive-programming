#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    string s;
    while(cin >> s) {
        reverse(s.begin(), s.end());
        cout << s;
        c = cin.get();
        if(c != EOF)
          cout << c;
    }
}
