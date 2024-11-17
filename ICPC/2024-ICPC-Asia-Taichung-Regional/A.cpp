#include<bits/stdc++.h>

using namespace std;

int main() {
  int i;
  int sum = 15;
  while(cin >> i) {
    sum -= i;
  }
  cout << sum;
}
