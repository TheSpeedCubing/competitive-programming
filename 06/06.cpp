#include <stdio.h>
#include <string.h>

int v[1024], z = 1023, i, b;
int main() {
    char n[1024];
    while (scanf("%s", n) != EOF) {
        for (i = 0; i < z; i++) {
            if (i < strlen(n))
                v[i] += n[strlen(n) - i - 1] - 48;
            v[i + 1] += v[i] / 10;
            v[i] %= 10;
        }
    }
    while (z--) {
        if (v[z])
            b = 1;
        if (b)
            printf("%d", v[z]);
    }
    printf("\n");
}