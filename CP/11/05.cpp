#include <bits/stdc++.h>
using namespace std;

int main()
{
	double x , p;
	while(cin >> x >> p) {
		 double low = 0, high = x ,mid;
		 while(1){
		 	  mid = (low + high) / 2.0;
		 	  double error = mid * mid - x;
		 	  if(fabs(error/x) <= p)
		 	     break;
		 	  error < 0 ? low = mid : high = mid;
		 }
		 printf("%.6f\n",mid);
	 }
}
