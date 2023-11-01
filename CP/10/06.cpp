#include <iostream>
#include <string>

using namespace std;

int main()
{
	  string HELLOMYFRIEND;
	  while(getline(cin,HELLOMYFRIEND)) {
	  	int flag = 1,c=9;
	  	while(c--) {
	  		int res=477, res2=477, res3=477, j=9;
	  		while(j--){
	  			 res -= HELLOMYFRIEND[c+j*9];
	  			 res2 -= HELLOMYFRIEND[c*9+j];
	  		   res3 -= HELLOMYFRIEND[c*3 + c/3*18 + j +j/3*6];
	  		}
	  		flag = flag && res == 0 && res2 == 0 &&res3==0;
	  	}
	  	printf(flag?"Yes\n":"No\n");
	  }
}
