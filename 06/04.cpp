#include <stdio.h>

int main() {
    char n[10000], m[10000];
    while (scanf("%s %s", n, m) != EOF) {
        int c[256] = {0}, count, last = 32,i=0,j=0;
        for (;n[i]; i++) {
            if (last != n[i]) {
                if (c[last] < count)
                    c[last] = count;
                count = 1;
            } else
                count++;
            last = n[i];
        }
        if (c[last] < count)
            c[last] = count;
        for (; m[j]; j++)
            printf(m[j+1] ? "%d " : "%d\n", c[m[j]]);
    }
}