#include <iostream>

using namespace std;

long long pow(int n) {
  long long i = 1;
  while (n--)
    i *= 10;
  return i;
}

int main() {
  long long a;
  while (cin >> a) {
    if (a < 10) {
      cout << a;
    } else {
    	
    	long long aCopy = a;
    	int digitCnt = 0;
    	while(aCopy){
    		 aCopy/=10;
    		 digitCnt++;
    	}
    	
      int p = pow(digitCnt - 1);
      if (!(a % p) && a / p == 1) {
        a--;
        digitCnt--;
      }
      
      long long p2 = pow(digitCnt/2) , 
                left = a / p2, 
                leftUnsure = left / (digitCnt % 2 ? 10 : 1),
                leftUnsureCopy = leftUnsure,
                reverseU = 0;
      
      while (leftUnsureCopy) {
          reverseU = reverseU * 10 + leftUnsureCopy % 10;
          leftUnsureCopy /= 10;
      }
  
      int flag = (a % p2) < reverseU;
      cout << left - flag;
      
      a = leftUnsure - (flag && !(digitCnt % 2 && left%10));
      while (a) {
         cout << a % 10;
         a /= 10;
      }
    }
    cout << "\n";
  }
}
