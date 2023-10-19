#include <stdio.h>

int main(){
  int n,a,max,st,ori;
  scanf("%d",&n);
  while(n){
	a = st = 0;
	ori = n;
	max = n==1;
	while(n != 1){
	  if(n > max){
		max=n;
		a=st;
      }
      st++;
	  n = n%2 ? n*3+1 : n/2;
	}
	printf("%d %d %d %d\n",ori,a,max,st);
	scanf("%d",&n);
  }
}