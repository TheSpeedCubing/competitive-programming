#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    ifstream file(argv[1]);
    char c;
    
    while (file.get(c)) {
        putchar(isalpha(c) ? ((isupper(c) ? 155 : 219) - c) : (isdigit(c) ? 105 - c : c));
    }
}
