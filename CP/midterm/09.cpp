#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int dt[1024];
	while(n){
		int l=0;
		for(int i = 0;i<n;i++){
			scanf("%d",&dt[i]);
			dt[i] = 1 - dt[i];
			if(!dt[i]){
				 l = i;
			}
		}
		for(int i = 0;i<n;i++){
			printf(i==n-1?"%d\n":"%d ",l<=i?1-dt[i]:dt[i]);
		}
		
		
	  scanf("%d",&n);
	}
}
