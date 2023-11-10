#include <iostream>

int main() {
	double a=0,b=0,c,d;
    while (std::cin >> c >> d) {
    	a+=c; 
    	b+=d;
    }
    printf("%.2f", b/a);
}
