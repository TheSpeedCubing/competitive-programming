#include <stdio.h>

int main() {
  int target,n;
  scanf("%d", & target);
  while (target) {
    n = target;
    while(n--){
      int temp = n,sum=n;
      while (temp) {
        sum += temp % 10;
        temp /= 10;
      }
      if(sum == target){
      	break;
      }
    } 
    printf(n<0?"-\n":"%d\n",n);
    scanf("%d", & target);
  }
}