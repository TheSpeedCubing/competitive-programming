#include <stdio.h>
int main() {
	int head,data;
	scanf("%d",&head);
	do{
		scanf("%d",&data);
    printf("%d\n",data);
	} while(data != head);
}