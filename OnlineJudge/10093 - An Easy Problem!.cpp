#include <stdio.h>

int main() {
    char s[1024];
    while(scanf("%s",s) != EOF) {
        int N = 2;
        int sum = 0;
        for(int i = 0;s[i];i++){
            int c = s[i];
            if('0' <= c && c <= '9'){
                 c = c - '0';
            } else if ('A' <= c && c <= 'Z'){
                 c = c - 'A' + 10;
            } else if ('a' <= c && c <= 'z'){
                 c = c - 'a' + 10 + 26;
            } else continue;
            if(c + 1 > N)
                N = c + 1;
            sum += c;
        }
        for (;N <= 62; N++)
            if (sum % (N-1) == 0) {
                printf("%d\n",N);
                break;
            }
        if (N == 63)
          printf("such number is impossible!\n");
    }
}
