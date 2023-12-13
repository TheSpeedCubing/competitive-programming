#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int T;
	cin >> T;
	
	for(int t = 1;t<=T;t++){
	int n;
	cin >> n;
	bool odd = n % 2;
	n -= odd;
	 
	 string s = bitset<32>(n).to_string();
	 int l = s.length();
	 int r[1024] = {odd};
	 for(int i = 1;i<l;i++){
	 	 char c = s[l - i - 1];
	 	 if(c - 48) {
	 	 	  if(i%2) { //negative
	 	 	  	if(r[i]) {
	 	 	  		r[i]--;
	 	 	  	} else {
	 	 	  	r[i]++;
	 	 	  	r[i+1]++;
	 	 	  	}
	 	 	  } else { //positive
	 	 	  	if(r[i]) {
	 	 	  		r[i]--;
	 	 	  		r[i+1]++;
	 	 	  		r[i+2]++;
	 	 	  	} else {
	 	 	  		r[i]++;
	 	 	  	}
	 	 	  }
	 	 }
	 }
	 cout << "Case #"<<t<<": ";
	 bool f = 0;
	 r[32] = 0;
	 for(int i = 1023;i>=0;i--){
	 	 f = r[i] || f;
	 	 if(f)
	 	  cout << r[i];
	 }
	 if(!f)
	 cout << 0;
	 cout << "\n";
}
	
}
