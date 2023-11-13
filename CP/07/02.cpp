#include <stdio.h>

int main() {
  	double x;
    unsigned long long b;
    unsigned long long y;
    while (scanf("%lf", &x) != EOF) {
    	  y = *(long long *) &x;
        printf("%g %g %llu\n", x, y, y);
    }
}
