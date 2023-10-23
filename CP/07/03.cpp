#include <stdio.h>

int main() {
	double a=0,c;
	int b=0,d;
    while (scanf("%lf %d", &c, &d) != EOF) {
    	a+=c; b+=d;
    }
    printf("%.2f", b/a);
}