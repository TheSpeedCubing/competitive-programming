#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        double y = 1;
        while (n--)
            y *= n + 1;
       cout << (int)(y / pow(10, (int) log10(y)))<<"\n";
    }
}