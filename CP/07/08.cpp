#include <stdio.h>
#include <math.h>

int main() {
    double val;
    while (scanf("%lf", & val) != EOF) {
        int fe = floor(log10(fabs(val))), flag = fe >= 0;
        printf("%s%d\n", flag ? "+" : "", flag ? fe + 1 : fe);
    }
}