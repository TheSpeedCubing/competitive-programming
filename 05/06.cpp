#include <stdio.h>

unsigned b, b2, b3, b4;
void a() {
  scanf("%u%u%u%u", & b, & b2, & b3, & b4);
}
int main() {
  a();
  while (b || b2 || b3 || b4) {
    printf("%d\n", b4 + (b3 << 8) + (b2 << 16) + (b << 24));
    a();
  }
}