#include <stdio.h>

int main() {
  int c;
  scanf("%d ",&c);
  while(c--){
  	int b,total=0,i=16;
    while(i--){
    	scanf("%1d",&b);
    	total+= i%2 ? (b*2 - (b < 5?0:9)) : b;
    }
    printf("%s\n",total%10?"Invalid":"Valid");
  }
}