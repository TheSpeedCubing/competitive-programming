#include <stdio.h>

int main() {
  long long n, val, t, i, VALUE;
  scanf("%lld", & n);
  while (n) {
    val = t = 0;
    for (i = 1; val < n;i++) {
      t += i;
      val += t;
      VALUE = val <= n ? i : VALUE;
    }
    printf("%lld\n", VALUE);
    scanf("%lld", & n);
  }
}