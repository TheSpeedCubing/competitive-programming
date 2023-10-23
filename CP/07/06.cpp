#include <stdio.h>
#include <math.h>

int main() {
    int s, a;
    char d[8];
    while (scanf("%d%d%s", & s, & a, d) != EOF) {
       double m = 6440 + s , n = a % (d[0] == 'd' ? 360 : 21600);
        n = d[0] == 'm' ? n / 60 : n;
        n = n > 180 ? 360 - n : n;
        printf("%.6f %.6f\n", m * 3.141592653589793 * n / 180, 2 * m * sin(n / 360 * 3.141592653589793));
    }
}