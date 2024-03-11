#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

unsigned char data[32768];

unsigned char* p = data;

int a, b, f, n;

template<typename T>
void pr(T* p2,string dataType, int size,const char* d) {
    cout << dataType;
    for (int i = 0; i < n; i++)
        printf(d, i % size ? " " : (i ? "\n" : ""),*(p2++));
    cout << "\n";
    p += n * (16 / size);
}

int main() {
    cin >> n;

    while (n--) {
        scanf("%hhX", p++);
    }
    p = data;

    string s;
    while (cin >> a >> s >> n) {
        if (f++)
            cout << "\n";
        p += a;
        if (s == "t") {
            cout << "Strings:\n";
            char* pp = (char*) p;
            while(n--) {
                puts(pp);
                pp += strlen(pp) + 1;
            }
            p = (unsigned char * ) pp;
        }
        if (s == "b") {
           pr(p, "Bytes:\n", 16,"%s%02X");
        }
        if (s == "i") {
           pr((int*) p, "Integers:\n", 4,"%s%d");
        }
        if (s == "ll") {
           pr((long long*) p, "Long long integers:\n", 2,"%s%lld");
        }
        if (s == "s") {
           pr((short*)p, "Short integers:\n", 8,"%s%d");
        }
        if (s == "f") {
           pr((float*) p, "Floats:\n", 4,"%s%e");
        }
        if (s == "d") {
           pr((double*) p, "Doubles:\n", 2,"%s%e");
        }
    }
}
