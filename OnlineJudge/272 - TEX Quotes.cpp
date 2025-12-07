#include <bits/stdc++.h>

using namespace std;

int main() {
    char c;
    
    bool f = true;
    while((c = getchar()) != EOF) {
        if(c != '"') {
            cout << c;
            continue;
        }
        if(f) {
            cout << "``";
        } else {
            cout << "\'\'";
        }
        f = !f;
    }
}