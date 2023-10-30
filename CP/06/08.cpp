#include <iostream>

#include <string>
using namespace std;

int main() {
	int b = 0;
	string n;
  while (getline(cin,n)) {
    if (b)
      printf("\n");
    else b = 1;
    	
    int l = n.length() , v[1024]={0},i=0,f=0,c=0,m,t=1023;

    if (n == "0")
      cout << "0\n0";
    else if (n == "1")
       cout <<"2\n0";
    else {
      for (;i < t; i++) {
        if (i < l)
          v[i] += (n[l - i - 1] - 48) * 2;
        v[i + 1] += v[i] / 10;
        v[i] %= 10;
      }
      while (t--) {
        if (v[t])
          f = 1;
        if (f)
          cout << v[t];
      }
      
      cout <<"\n";
      
      for (i = 0; i < l; i++) {
        if (n[i] == 1) {
          n[i + 1] += 10;
        } else {
        	m = (n[i] - 48) / 2;
        	if(!c)
        	  c= m;
          if (n[i] && c || m)
             cout << m;
          if ((n[i] - 48) % 2 != 0)
            n[i + 1] += 10;
        }
      }
      
    }
      printf("\n");
  }
}