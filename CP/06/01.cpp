#include <iostream>
using namespace std;

int main() {
    char a, f;
    while ((a = getchar()) != EOF) {
        if (isalpha(a)) {
        	  a = f ? toupper(a) : tolower(a);
            f = !f;
        } 
        if (a == '\n')
            f = 1;
        cout << a;
    }
}