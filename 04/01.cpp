#include <stdio.h>

int main() {
	int head,data;
	scanf("%d%d",&head,&data);
    while(data != head){
    	printf("%d\n",data);
    	scanf("%d", &data);
    }
    printf("%d\n",data);
}