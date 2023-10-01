#include <stdio.h>

int d[4],i,die;
int f(int k) {
	int ori = 0;
	for(int i = 0;i<4;i++)
		  if(d[i]==k)
			    ori++;
  return ori;
}
int main()
{
    scanf("%d", &die);
    while(die) {
      	int sum=0,k=0,xx[6],s=0;
      	for(i = 0;i<4;i++){
    		    d[i] = die%10;
    		    sum += d[i];
    		    die /= 10;
    	  }
        bool t = false, alr = false;
        for(i =0;i<6;i++) {
        	  s+=2;
        	  xx[i] = f(i+1);
        	  t = (t||xx[i]==3);
        	  if(xx[i])
        	      k++;
        	  if(xx[i]==2 && !alr){
          	   sum-=s;
      	       alr=true;
        	  }
        }
        if(k==4||t) 
            printf("-\n");
        else {
            if(k==1 || sum == 12) 
                printf("SiPaLa\n");
            else if(sum==3) 
                printf("BG\n");
            else
                printf("%d\n", sum);
        }
        scanf("%d", &die);
    }
}