#include <iostream>

using namespace std;

 int yy,mm,flag;
 
int main()
{
	string month[] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
 
  
  while(cin >> yy >> mm) {
  	
  	   if(flag)
  	     cout <<"\n";
  	   else flag = 1;
  	   
  	   mm = -mm;
  	   
	    int data[] = {0,31,28+((!(yy % 4) && yy % 100) || !(yy % 400))
		,31,30,31,30,31,31,30,31,30,31},
		
		  y = yy - (mm <3),
	    m = mm + (mm < 3 ? 10 : -2),
	    c = y / 100;
	    
	    y %=100;
	    
	    int w = (int) (1+floor(2.6*m-0.2)+y+floor(y/4)+floor(c/4)-2*c) %7;
	    w = w < 0 ? w + 7 : w;
	    
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




