#include <stdio.h>

int main() {
  unsigned a,sum;
  scanf("%d", & a);
  while (a) {
    while (a > 9) {
      sum = 0;
      while (a) {
        sum += a % 10;
        a /= 10;
      }
      a = sum;
    }
    printf("%d\n", a);
    scanf("%d", & a);
  }
}