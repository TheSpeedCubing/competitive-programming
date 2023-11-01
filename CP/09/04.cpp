#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int yy,m1,m2,flag=1;
	while(cin >> yy >> m1 >> m2){
		
		if(flag)
		  flag=0;
		else cout <<"\n";
		
		int data[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
		data[2] += (yy%4 ? (yy%100 ? !yy%400 : 0) : 1);
		
		for(int mm = m1;mm <= m2;mm++){
	     for(int dd = 1;dd<=data[mm]; dd++){
	     	  int y = yy - (mm <3);
	     	  int m = mm + (mm < 3 ? 10 : -2);
	     	  int c = y / 100;
	     	  y%=100;
	     	  int w = (int) (dd+floor(2.6*m-0.2)+y+floor(y/4)+floor(c/4)-2*c) %7;
	     	  if(w == -1 || w == 0 || w == 6)
	     	    printf("%02d/%02d/%04d\n",dd,mm,yy);
	     }
		}
	}
}
