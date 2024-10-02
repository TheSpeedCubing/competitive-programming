#include <bits/stdc++.h>

using namespace std;

int main() {
  int i;
  while(cin >> i && i){
  	int n[1024],v=0,session=0,in;
    while(i--) {
   		cin >> in;
	    if(in) {
        session += (int) pow(2,i%4);
	    }
	    if(i%4==0){
		    v = session > v ? session : v; 
		    session = 0;
      }
    }
    cout << (v>9?"H\n":(v>7?"HD\n":(v>1?"HDO\n":"HDOB\n")));
  }
}
