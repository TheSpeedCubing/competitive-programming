#include <stdio.h>

int main() {
    int a, c, d, e, max, min, v;
    scanf("%d", &a);
    while (a--) {
        max = v = 0;
        min = 2147483647;
        scanf("%d", &c);
        for (d = 1; d <= 3; d++) {
            scanf("%d", &e);
            v += e;
            if (max < e)
                max = e;
            min = min > e ? e : min;
        }
        printf(c == 0 ? "0\n" : (c <= max ? "1\n" : (c <= v - min ? "2\n" : (c <= v ? "3\n" : (c > v ? "4\n" : "")))));
    }
}