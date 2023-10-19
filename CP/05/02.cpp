#include <stdio.h>

int main() {
  char n[16];
  scanf("%s", & n);
  while (n[0] - 48) {
  	for(int i =0;n[i];i++)
      printf("%c%s", n[i], n[i+1] ? "   " : "\n");
    scanf("%s", & n);
  }
}