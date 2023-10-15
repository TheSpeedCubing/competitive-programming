#include <stdio.h>

int main() {
    char n[32768], m[32768];
    while (scanf("%s %s", n, m) != EOF) {
        int c[256] = {0}, count = 0, i=0,j=0;
        while(n[i]) {
            count++;
            if (n[i] != n[i+1]) {
                if (c[n[i]] < count)
                    c[n[i]] = count;
                count = 0;
            }
            i++;
        }
        while(m[j]) {
            printf(m[j+1] ? "%d " : "%d\n", c[m[j]]);
            j++;
        }
    }
}