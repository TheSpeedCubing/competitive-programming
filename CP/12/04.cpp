#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	string month[] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
  int yy,mm,flag = 1;
  
  while(cin >> yy >> mm) {
  	
  	   if(flag)
  	     flag = 0;
  	   else cout <<"\n";
  	   
  	   mm = -mm;
  	   
	    int y = yy - (mm <3);
	    int m = mm + (mm < 3 ? 10 : -2);
	    int c = y / 100;
	    y%=100;
	    int w = (int) (1+floor(2.6*m-0.2)+y+floor(y/4)+floor(c/4)-2*c) %7;
	    w = w < 0 ? w + 7 : w;
	    
	    int data[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
	    data[2] += (!(yy % 4) && yy % 100) || !(yy % 400);
	    
	    cout << month[mm] <<", "<<yy<<"\nSun Mon Tue Wed Thr Fri Sat\n";
	    
	    for(int i = -w + 1;i<=data[mm];i++){
	    	int ref = (i + w - 1) % 7;
	    	if(ref)
	    	   cout <<" ";
	    	   
	    	printf((i < 1 ? "   " : "%3d"),i);
	    	
	    	if(ref == 6 || i == data[mm])
	    	  cout <<"\n";
	    }
  }
}




