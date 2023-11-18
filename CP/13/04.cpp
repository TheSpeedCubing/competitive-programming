#include <iostream>

using namespace std;

long long t(long long i,int type) {
		 long long d = 1,maX = 0,miN = 0x7FFFFFFFFFFFFFFF;
		 while(i / d) {
		   long long k = (i / (d*10)) * d + i % d;
		   maX = max(k,maX);
		   miN = min(k,miN);
		 	   d *= 10;
		  }
		  return type ? maX : (miN == 0x7FFFFFFFFFFFFFFF ? 0 : miN);
}

int main() {
	int T;
	cin >> T;
	for(int j = 1;j<=T;j++){
		 cout << "Case "<<j<<":\n";
		 long long i, T2;
		 cin >> i >> T2;
		 
		 long long MAX[20] = {i}, MIN[20] = {i};
		 
		 for(int m = 0;m<19;m++) {
		 	  MAX[m+1] = t(MAX[m],1);
		 	  MIN[m+1] = t(MIN[m],0);
		 }
		 
		 int v;
		 while(T2--) {
		 	cin >>v; 
		 	cout << MAX[v] <<" "<<MIN[v]<<"\n";
		 }
	}
}
