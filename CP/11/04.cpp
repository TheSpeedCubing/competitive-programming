#include <iostream>

using namespace std;

long long M, n, dt[32768];

int main() {

  while (cin >> M >> n) {
  	
    int i = n;
    while (i--)
      cin >> dt[i];

    int result = dt[0], j = 1;
    
    while (j < n) {
    	
      int a = result, b = dt[j++];
      while (b) {
        int temp = b;
        b = a % b;
        a = temp;
      }
      
      result = a;
    }
     
    cout << (M % result ?"No\n" : "Yes\n");
  }
}
