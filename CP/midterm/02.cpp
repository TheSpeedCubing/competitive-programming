#include <stdio.h>

int main()
{
	int a,b;
	
	while(1){
		scanf("%d %d",&a,&b);
		if(a==0 && b ==0)
		  return 0;
		  
		if(a > b){
			printf("%d %d\n",a-b+1,a+b-1);
		} else if(a<b) {
			printf("%d %d\n",b-a+1,b+a-1);
		} else {
			printf("%d %d\n",1,a+b-1);
		}
	}
    return 0;
}
