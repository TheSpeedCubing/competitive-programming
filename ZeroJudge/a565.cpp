#include<stdio.h>

int main() {
  int T;
  char c;
  
  scanf("%d\n", & T);
  
  while(T--) {

    int count = 0;
    int pCount = 0;
    while (1) {
      c = getchar();
      if (c == '\n' || c == EOF) {
        break;
      }
      if (c == 'p') {
      	pCount++;
      }
      if (c == 'q') {
        if(pCount > 0) {
           pCount--;
      		 count++;
      	}
      }
    }
    printf("%d\n", count);
  }
}
