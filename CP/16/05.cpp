#include <bits/stdc++.h>

using namespace std;

int main(){
   string s, in;
   int i;
   while(cin >> i) {
   	  getline(cin,in);
   	  if(i) {
   	    in = in.substr(1, in.size() - 2);
   	    s = (i == 1 ? s + in : in + s);
   	  } else {
   	  	 cout << s <<"\n";
   	  	 s = "";
   	  }
   }
}
