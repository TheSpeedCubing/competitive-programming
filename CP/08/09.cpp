#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int cnt, size, flag=1,i;
    while(cin >> cnt >> size){
      double dist[1024] = {0};
        if(flag) 
		      flag = 0;
        else 
		      printf("\n");
        for(i = cnt - 1 ; i ;i--)
            dist[i-1] = dist[i] + size / 2.0 / i;
        for(i = 0;i < cnt;i++) {
        	int j = 0,cp=size;
        	for(;j<floor(dist[i]);j++)
        		printf(" ");
        	while(cp--)
			    	printf("*");
          printf("\n");
        }
    }
}