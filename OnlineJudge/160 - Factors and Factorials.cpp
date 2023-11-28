#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n && n != 0) {
	  int arr[100];
	  for(int i = 0;i<100;i++){
	  	arr[i] = -1;
	  }
	  
		for(int f = n;f > 1;f--) {
      
      int fCopy = f;
      for (int i = 2; i <= fCopy; i++) {
         while (fCopy % i == 0) {
        	   if(arr[i] == -1){
        	 	   arr[i] = 0;
        	   }
        	  arr[i]++;
            fCopy /= i;
        }
      }
      
		}
		
		printf("%3d! =",n);
		int printCnt = 0;
		for(int i = 0;i<100;i++){
			if(arr[i] != -1) {
				 if(printCnt % 15 == 0 && printCnt != 0) {
				 	 cout <<"\n      ";
				 }
				 printf("%3d",arr[i]);
				 printCnt++;
			}
		}
		cout <<"\n";
	}
}
