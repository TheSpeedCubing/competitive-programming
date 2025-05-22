#include<bits/stdc++.h>

using namespace std;

int main() {
  int size = 1000001;
  bool notPrime[size] = {}; // inversed table
  vector<int> primes;
  
  for (int i = 2; i <= sqrt(size); i++) {
    if (!notPrime[i]) {
      int k = i * i;
      while (k < size) {
        notPrime[k] = true;
        k += i;
      }
    }
  }
  
  for (int i = 2; i < size; i++) {
    if (!notPrime[i]) 
      primes.push_back(i);
  }
  
  int n;
  while (cin >> n && n) {
    int found = -1;
    for (int p : primes) {
      if (p > n)
        break;
      if (!notPrime[n - p]) {
        found = p;
        break;
      }
    }
    if (found != -1)
      cout << n << " = " << found << " + " << (n-found) << "\n";
    else 
      cout << "Goldbach's conjecture is wrong.\n";
  }
}
