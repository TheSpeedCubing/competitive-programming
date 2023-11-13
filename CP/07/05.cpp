#include <iostream>

using namespace std;

int main() {
    while (1) {
        double locx[4], locy[4];
        int i=0;
        while(i<4) {
    	  	if (!(cin >> locx[i] >> locy[i++]))
    	  	  return 0;
        }
        
    	  int t2 = locx[1] == locx[2] && locy[1] == locy[2],
    	      a = (locx[1] == locx[3] && locy[1] == locy[3]) || t2,
    	      c = ((locx[0] == locx[2] && locy[0] == locy[2]) || t2) + 2;
    	      
        printf("%.3f %.3f\n", locx[!a] + locx[c] - locx[a], locy[!a] + locy[c] - locy[a]);
    }
}
