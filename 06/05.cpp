#include <stdio.h>

int main() {
    char c;
    int m, a, b, ct, cp;
    while(scanf("%c%d%d%d ", &c, &m, &a, &b) != EOF){
    	  ct = b < 0 ? -b : b;
        cp = (a < 0 ? (m - (-a % m)) : a) % m;
        while(ct--){
            printf("%c", (c - 97 + cp) % 26 + 97);
            cp = (cp + (b < 0 ? m - 1 :1)) % m;
        }
        printf("\n");
    }
}