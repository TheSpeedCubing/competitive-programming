#include <stdio.h>

int main() {
	int row[4] = {0,0,0,0};
	int column[4] = {0,0,0,0};
    int i = 1 , x,j=0,k=0;
    while(i<=16){
    	 scanf("%d",&x);
    	 row[(i-1)/4]+=x;
    	 column[(i-1)%4]+=x;
    	 if((i-1)%5 == 0)
    	 	j +=x;
    	 if((i-1)%3 == 0 && i != 16 && i != 1)
    	  	k +=x;
    	 printf("%2d%s",x,i%4==0?"\n":" ");
    	i++;
    }
    printf("\nRow sums:");
    for(i = 0;i<4;i++){
    	printf(i==3?"%d\nColumn sums:":"%d ",row[i]);
    }
    for(i = 0;i<4;i++){
    	printf(i==3?"%d\nDiagonal sums:%d %d\n":"%d ",column[i],j,k);
    }
}
