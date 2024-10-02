#include <stdio.h>

int main() {
  long long n, sum, n2;
  
  while (scanf("%lld", &n) && n) {
    sum = 0;
    n2 = n;
    n++;
  	while(n--) {
      sum += n * (n2 - n + 1);
  	}
    printf("%lld\n", sum);
  }
}
