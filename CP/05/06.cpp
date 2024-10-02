#include <stdio.h>

unsigned b, b2, b3, b4;

int main() {
  while (1) {
    scanf("%u%u%u%u", &b, &b2, &b3, &b4);
    if(!(b || b2 || b3 || b4)) {
  		return 0;
  	}
    printf("%d\n", b4 + (b3 << 8) + (b2 << 16) + (b << 24));
  }
}
