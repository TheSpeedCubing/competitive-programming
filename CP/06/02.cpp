#include <stdio.h>

int main() {
    int k,kinvert,t,i;
    char n[1024], c;
    scanf("%d", &t);
        while(t--){
            kinvert = i = 0;
            scanf("%d%s", &k, n);
            while(kinvert * k%37 - 1)
                kinvert++;
            while(c = n[i]){
                c = kinvert *
          	        (c == '+' ? 0:
        	            (c - (c > 64 ? 64 : 21))
        	        ) % 37;
                printf("%c", c ? c + (c > 26 ?21 :64) : '+');
                i++;
            }
        printf("\n");
    }
}