#include <stdio.h>

int main() {
	  int a,i=25;
    while(i--) {
        scanf("%d", &a);
        printf((i+4)%5==4?"%2d\n":"%2d ", a);
    }
}