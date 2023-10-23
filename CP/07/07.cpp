#include <stdio.h>

#include <math.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        double y = 1;
        while (n--)
            y *= n + 1;
        printf("%d\n", (int)(y / pow(10, (int) log10(y))));
    }
}