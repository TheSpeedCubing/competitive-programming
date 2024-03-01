#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while(cin >> s){
		int result = 1;
		for(int i = 1;i<=s.length()/2;i++) {
			 if(!(s.length()%i)) {
			 	  bool f = true;
			 	  int j = i;
			 	  while(j--) {
			 	  	 int k = i;
			 	  	 while(k<s.length() && f) {
			 	  	 	 f = f && s[j] == s[j+ k];
			 	  	 	 k+=i;
			 	  	 }
			   }
			   if(f) {
			   	  result = s.length()/i;
			 	  	break;
			   }
		  }
	  }
	  cout <<result<<"\n";
  }
}
