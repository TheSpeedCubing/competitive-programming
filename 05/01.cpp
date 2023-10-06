#include <stdio.h>

int main() {
  unsigned a, b, c, x;
  scanf("%u %u", & a, & b);
  while (a && b) {
    c = 0;
    x = a ^ b;
    while (x) {
      c++;
      x &= (x - 1);
    }
    x = c;
    c = 0;
    while (a != b) {
      if (a % 10 != b % 10)
        c++;
      a /= 10;
      b /= 10;
    }
    printf("%d %d\n",c, x);
    scanf("%u %u", & a, & b);
  }
}