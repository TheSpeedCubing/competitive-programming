#include <iostream>

double a,b,c,d;

int main() {
	
    while (std::cin >> c >> d) {
    	a+=c; 
    	b+=d;
    }
    printf("%.2f", b/a);
}
