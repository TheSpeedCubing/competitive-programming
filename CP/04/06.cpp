#include <stdio.h>

int main(){
    int h, a,m;
    scanf("%d", &h);
    while(h--){
        scanf("%d", &a);
        m=a > m ? a : m;
    }
    printf("%d\n", m);
}