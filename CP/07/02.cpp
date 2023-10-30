#include <stdio.h>
#include <math.h>

int main() {
    double x, A;
    unsigned long long b;
    unsigned long long y;
    while (scanf("%lf", & x) != EOF) {
        A = fabs(x), b = 1023,y = 0;

        while (A >= 2) {
            b++;
            A /= 2;
        }

        while (A < 1) {
            b--;
            A *= 2;
        }
        A -= 1;
        
        int n = 52;
        while (n--) {
            b *= 2;
            A *= 2;
            y *= 2;
            if (A >= 1) {
                y++;
                A--;
            }
        }
        
        y += b;
        if (x < 0)
            y += 9223372036854775808;
        printf("%g %g %llu\n", x, y, y);
    }
}