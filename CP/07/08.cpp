#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double val;
    while (cin >> val) {
        int fe = floor(log10(abs(val))), flag = fe >= 0;
        cout << (flag ? "+" : "") << (flag ? fe + 1 : fe) << "\n";
    }
}