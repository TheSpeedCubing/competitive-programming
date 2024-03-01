#include <iostream>

using namespace std;

typedef unsigned long long Oh;

Oh pow10(int n) {
  Oh i = 1;
  while (n--)
    i *= 10;
  return i;
}

int main() {
  Oh n;
  while (cin >> n) {
    if (n < 10) {
      cout << n;
    } else {
    	
    	Oh buf = n;
    	int digitCnt = 0;
    	while(buf){
    		 buf/=10;
    		 digitCnt++;
    	}
    	
      int p = pow10(digitCnt - 1);
      if (!(n % p) && n / p == 1) {
        n--;
        digitCnt--;
      }
      
      long long p2 = pow10(digitCnt/2) , 
                left = n / p2, 
                leftUnsure = left / (digitCnt % 2 ? 10 : 1),
                leftUnsureCopy = leftUnsure,
                reverseU = 0;
      
      while (leftUnsureCopy) {
          reverseU = reverseU * 10 + leftUnsureCopy % 10;
          leftUnsureCopy /= 10;
      }
  
      buf = (n % p2) < reverseU;
      cout << left - buf;
      
      n = leftUnsure - (buf && !(digitCnt % 2 && left%10));
      while (n) {
         cout << n % 10;
         n /= 10;
      }
    }
    cout << "\n";
  }
}
