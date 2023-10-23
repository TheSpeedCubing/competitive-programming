#include <stdio.h>

int main(){
  double x;
  while(scanf("%lf", &x)!=EOF){
      int n = 52;
      x--;
      while(n--){
        x *= 2;
        printf("%d", x >= 1);
        x -= x >= 1 ? 1 : 0;
      }
      printf("\n");
    }
}