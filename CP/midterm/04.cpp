#include <stdio.h>
#include <bitset>

// 這個「副程式」給你參考，可以呼叫。會用，就很簡單！
int diff(unsigned int a, unsigned int b, int r) {
    int d = 0;
    for (; a != b; a /= r, b /= r)
        if (a % r != b % r) d++;
    return(d);
}

int main()
{
	unsigned a,b;
	while(1){
	  scanf("%u %u",&a,&b);
	if(a==0&&b==0)
	  return 0;
	  printf("%d %d %d\n",diff(a,b,10) ,diff(a,b,16) ,diff(a,b,2) );
	}
}
