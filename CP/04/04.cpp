#include <stdio.h>

int main() {
    int i =1,j;
    while (i<9){
        if (i>1)
            printf("\n");
        j = 1;
        while(j <= 9){
            printf("%d * %d = %2d\t%d * %d = %2d\t%d * %d = %2d\n",
                    i, j, i * j,
                    i + 1, j, (i + 1) * j,
                    i + 2, j, (i + 2) * j
            );
            j++;
        }
        i+=3;
    }  
}