#include <float.h>
#include <stdio.h>
#include <algorithm>

char str[32768], c;
int size;


template<typename T>
void find(T* p,const char* name, const char* type) {
    T t1 = p[0];
    T t2 = p[0];
    for (int i = 0; i < size /sizeof(T); i++) {
        t1 = std::min(t1, p[i]);
        t2 = std::max(t2, p[i]);
    }
    printf(name);
    printf(type,t1,t2);
    printf("\n");
}
int main() {
	printf("Data Type Min/Max\n========= =======\n");
	while((c = getchar()) != EOF) {
		 str[size++] = c;
	}
	size += (100000 - size) % 8;
	
	find((short*) str,"short     ", "%d/%d");
	find((int*) str,"int       ", "%d/%d");
	find((long long*) str,"long long ","%lld/%lld");
	find((float*) str,"float     ","%e/%e");
	find((double*) str,"double    ","%e/%e");
}

