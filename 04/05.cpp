#include <stdio.h>

int main() {
    int t, h, ch = 0, i;
    scanf("%d%d", &t, &h);
    while (ch < h) {
        i = 0;
        if (t == 1 || t == 4) {
            while (i <= ch) {
                printf("*");
                i++;
            }
        }

        while (i < (t == 2 || t == 3 ? h - ch - 1 : (t == 4 ? 2 * h - ch - 2 : i))) {
            printf(" ");
            i++;
        }
        while (i < (t == 2 ? h : (t == 3 ? h + ch : (t == 4 ? 2 * h - 1 : i)))) {
            printf("*");
            i++;
        }

        printf("\n");
        ch++;
    }
}
