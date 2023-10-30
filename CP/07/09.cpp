#include <iostream>
#include <math.h>
using namespace std;

double a(int x) {
  return sin(x*3.141592653589793/180);
}
double b(int x){
  return cos(x*3.141592653589793/180);
}

int main() {
    int n,x1, y1, x2, y2;
	 char hor,ver,hor2,ver2;
    cin >> n;
    while(n--){
    	  cin >> hor >> x1 >> ver >>y1>>hor2>>x2>>ver2>>y2;
        if(hor==87) x1 = -x1;
        if(ver==83) y1 = -y1;
        if(hor2==87) x2 = -x2;
        if(ver2==83) y2 = -y2;
        printf("%d\n",(int) floor(abs(6000*acos(a(y1)*a(y2)+b(y1)*b(y2)*(a(x1)*a(x2)+b(x1)*b(x2))))));
    }
}