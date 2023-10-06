#include <stdio.h>
#include <math.h>

int main() {
  int i;
  scanf("%d",&i);
  while(i){
  	int n[(i-1)/4+1],v=0,session=0,in;
   	while(i--) {
      scanf("%d",&in);
	  if(in)
	    session+= (int) pow(2,i%4);
	  if(i%4==0){
		v = session > v ? session : v; 
		session = 0;
      }
    }
    printf(v>9?"H\n":(v>7?"HD\n":(v>1?"HDO\n":"HDOB\n")));
    scanf("%d",&i);
  }
}
