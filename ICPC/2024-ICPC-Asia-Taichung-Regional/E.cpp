#include<bits/stdc++.h>

using namespace std;

int main() {
  int avg, median;
  
  cin >> avg >> median;
  
  cout << "3\n";
  
  /*
    (L + median + R) / 3 = avg
    L + R = avg * 3 - median
  */
  cout << -1000 << " " << median << " " << (avg * 3 - median) + 1000;
}
