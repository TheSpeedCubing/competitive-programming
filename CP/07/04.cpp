#include <stdio.h>
#include <math.h>

int main() {
    double d, e, f, flag = 1;
    while (scanf("%lf %lf %lf", & d, & e, & f) != EOF) {
    	
        if (flag)
            flag = 0;
        else
            printf("\n");

        double a = fmax(d, fmax(e, f)), c = fmin(d, fmin(e, f)), b = d + e + f - a - c;
        

        if (a >= b + c)
            printf("Not a triangle\n");
        else {
            if (a * a < b * b + c * c)
                printf("Acute triangle\n");
            if (a * a == b * b + c * c)
                printf("Right triangle\n");
            if (a * a > b * b + c * c)
                printf("Obtuse triangle\n");
            if (((b > c || c > b) && a == b) || (b == c && (a > b || a < b)))
                printf("Isosceles triangle\n");
            if (a == b && b == c)
                printf("Equilateral triangle\n");
        }
    }
}