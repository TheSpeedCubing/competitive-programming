#include <stdio.h>

int main() {
	int a, b, c, d, e, f;
	scanf("%d", &a);
	while(a--){
		e = 0;
		scanf("%d%d", &b, &c);
		while(c--){
			scanf("%d", &d);
			e += d;
		}
		f = b/e + (b%e?1:0);
		printf("Project will be completed within %d day%s", f,f>1?"s.\n":".\n");
	  }
}