#include <iostream>

using namespace std;

int main() {
	
	  int n,id;
	  while(cin >> n) {
	     int data[32768] = {0} , result[4] = {0} , testC=0,c=3,d=32768;
	     while(c--){
	  	    while(n--) {
	  		     cin >> id;
	  		     data[id]++;
	  	    }
	  	    if(c)
	  	      cin >> n;
	     }
	     while(d--)
	     	  if(data[d]) {
	     	    result[0]++;
	     	    result[data[d]]++;
	     	  }
	      cout <<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3]<<"\n";
	  }
}
