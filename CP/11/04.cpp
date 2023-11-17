#include <iostream>

using namespace std;

long long M, n, data[32768];

int main() {

  while (cin >> M >> n) {
  	
    int i = n;
    while (i--)
      cin >> data[i];

    int result = data[0], j = 1;
    
    while (j < n) {
    	
      int a = result, b = data[j++];
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
