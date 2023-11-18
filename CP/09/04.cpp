#include <iostream>
#include <cmath>
using namespace std;

int yy,mm,m2,flag;

int main()
{
	while(cin >> yy >> mm >> m2) {
		
		if(flag)
		  cout <<"\n";
		else flag = 1;
		
		int data[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
		
		
		data[2] += (!(yy % 4) && yy % 100) || !(yy % 400);
		
		while(mm <= m2) {
	     	  int y = yy - (mm <3),
	     	      m = mm + (mm < 3 ? 10 : -2),
	     	      c = y / 100,
	     	      dd = 1;
	     	      y%=100;
	     	    while(dd <= data[mm]){
	     	  int w = (int) (dd+floor(2.6*m-0.2)+y+floor(y/4)+floor(c/4)-2*c) %7;
	     	  if(w == -1 || w == 0 || w == 6)
	     	    printf("%02d/%02d/%04d\n",dd,mm,yy);
	     	    dd++;
	     	    }
	     mm++;
		}
	}
}
