#include <bits/stdc++.h>

using namespace std;

bool odd(int a) {
	return a % 2;
}
int main() {
   int n, m, i;
   while(cin >> n >> m) {
     cout << n <<" "<<m <<"\n";
     if (n == 0 && m == 0) {
   	   	return 0;
   	 }
     vector<int> v;
     while(n--) {
       cin >> i;
     	 v.push_back(i);
     }
     
     sort(v.begin(), v.end(), [m](int i1, int i2) {
        int m1 = i1 % m;
        int m2 = i2 % m;
         
         if(m1 != m2) {
         	 return m1 < m2;
         }
         
        if((odd(i1)^odd(i2))) {
     	  	 return i1 % 2 == 1;
        }
         
         if(odd(i1) && odd(i2)) {
     	  	return i1 > i2;
         }
         
         if(!odd(i1) && !odd(i2)) {
     	  	return i1 < i2;
         }
     });
     
     for(int i : v) {
     	cout << i <<"\n";
     }
   }
}
