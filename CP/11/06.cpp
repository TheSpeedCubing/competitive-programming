#include <iostream>
#include <math.h>
using namespace std;

int main() {
	  double x;
	  while(cin >> x){
	  	 double y = 1, dy;
	  	 while(1) {
	  	   dy = (x / y + y) /2;
	  	   if(fabs(y - dy) < 0.00001 * y)
	  	     break;
	  	   y = dy;
	  	 }
       printf("%.5f\n",dy);
	  }
}
