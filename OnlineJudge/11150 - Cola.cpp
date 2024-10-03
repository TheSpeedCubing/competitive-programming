#include <bits/stdc++.h>

using namespace std;

int main() {
   int n;
   while(cin >> n) {
      int bottle = n;
      int total = n;
	  
      while(bottle >= 3) {
		int receive = bottle /3;
        total += receive;
        bottle %= 3;
		bottle += receive; 
      }
	  
	  if(bottle == 2) {
		  total++;
	  }
   	  cout << total <<"\n";
   }
}
