#include <iostream>
using namespace std;

int main(){
  double x;
  while(cin >> x){
      int n = 52;
      x--;
      while(n--){
        x *= 2;
        cout << (x>=1);
        x -= (x >= 1);
      }
      cout <<"\n";
    }
}
