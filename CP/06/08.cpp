#include <stdio.h>

#include <string.h>

char n[1024], b;

int main() {
  while (gets(n) != NULL) {
    if (b)
      printf("\n");
    else b = 1;
    	
    int l = strlen(n) , v[1024]={0},i=0,f=0,c=0,m,t=1023;

    if (n[0] == '0')
      printf("0\n0");
    else if (n[0] == '1' && l == 1)
      printf("2\n0");
    else {
      for (;i < t; i++) {
        if (i < l)
          v[i] += (n[l - i - 1] - 48) * 2;
        v[i + 1] += v[i] / 10;
        v[i] %= 10;
      }
      while (t--) {
        if (v[t])
          f = 1;
        if (f)
          printf("%d", v[t]);
      }
      
      printf("\n");
      
      for (i = 0; i < l; i++) {
        if (n[i] == 1) {
          n[i + 1] += 10;
        } else {
        	m = (n[i] - 48) / 2;
        	if(!c)
        	  c= m;
          if (n[i] && c || m)
            printf("%d", m);
          if ((n[i] - 48) % 2 != 0)
            n[i + 1] += 10;
        }
      }
      
    }
      printf("\n");
  }
}