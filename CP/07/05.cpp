#include <stdio.h>

int main() {
    double locx[4], locy[4];
    while (1) {
        int a = 0, b = 1, c = 2,i=0;
    	  for(;i<4;i++){
    	  	if(scanf("%lf %lf",&locx[i],&locy[i]) == EOF)
    	  	  return 0;
    	  }
        if (locx[0] == locx[2] && locy[0] == locy[2]) {
            c = 3;
        } else if (locx[1] == locx[2] && locy[1] == locy[2]) {
            a = 1;
            b = 0;
            c = 3;
        } else if (locx[1] == locx[3] && locy[1] == locy[3]) {
            a = 1;
            b = 0;
        }
        printf("%.3f %.3f\n", locx[b] + locx[c] - locx[a], locy[b] + locy[c] - locy[a]);
    }
}