#include <stdio.h>

int main() {
  long long n, val,i;
  scanf("%lld", & n);
  while (n) {
  	val = 0,i = n + 1;
  	while(i--)
  	  val += i * (n-i+1);
    printf("%lld\n", val);
    scanf("%lld", & n);
  }
}