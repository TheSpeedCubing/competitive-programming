#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N, flag=1, xx[32768], yy[32768];

double fare, q[32768];

int trafficFare(double distance, double unitPrice)
{
	return trafficFare(distance,unitPrice);
}

double calcDistance(int x1, int y1, int x2, int y2)
{
    return round(sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) * 10) / 10.0;
}

void printTheFuckingHeader(int head){
		cout << (head ?"Traffic-Fare Table:\n  " : "Distance Table:\n");
		
		int i = 2, idx = 0;
		while (i<=N) {
			 printf("      %2d",i++);
		}
		
		cout << "\n==";
		
		i = 2;
		while (i<=N) {
			 cout << " =======";
			 i++;
		}
		
		cout <<"\n";
		
		i = 1;
		while (i<N) {
		  printf("%2d",i);
		  double d = 0;
		  for(int j = 1;j <N;j++) {
		  	  if(j >= i) {
		  	  	if(head) {
		  	      printf("%8d",fare ? (int) (round(q[idx++] * fare / 10.0)) : 1);
		  	  	} else {
		   	      d += calcDistance(xx[j-1],yy[j-1],xx[j],yy[j]);
		   	  	  q[idx++] = round(d*10);
		   	      printf("%8.1f",d);
		  	  	}
		  	  } else 
		        cout << "        ";
		  }
		  cout <<"\n";
		  i++;
		}
}

int main()
{
	while(cin >> N) {
		
		if(flag)
		  flag = 0;
		else cout <<"\n**********\n";
	  
		for(int i = 0;i<N;i++) {
	     cin >> xx[i] >> yy[i];
		}
		
		cin >> fare;
		
		printTheFuckingHeader(0);
		cout <<"\n";
		printTheFuckingHeader(1);
	}
}