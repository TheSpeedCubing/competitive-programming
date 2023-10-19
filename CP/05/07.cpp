#include <stdio.h>

int main() {
  int t,i,lasti,n[32768];
  scanf("%d", & t);
  while (t) {
    lasti = -1;
    for (i = 0; i < t; i++) {
      scanf("%d", & n[i]);
      n[i] = 1 - n[i];
      if(!n[i])
        lasti = i;
    }
    for (i = 0; i < t; i++)
      printf(i == t - 1 ? "%d\n" : "%d ",lasti<=i? 1-n[i] : n[i]);
    scanf("%d", & t);
  }
}