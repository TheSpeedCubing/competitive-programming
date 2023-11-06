#include <iostream>
using namespace std;

int main()
{
	 string s;
	 int v[32768];
	 for(int i = 0;i<32768;i++){
	 	v[i] = 0;
	 }
	 while(cin >> s){
	 	   for(int i = 0;i<32768;i++) {
	 	   	if(i < s.length()){
	 	   	 v[i] = v[i] + s[s.length()-i-1] - 48;
	 	   	}
	 	   	if(v[i] > 9) {
	 	   		  v[i+1]++;
	 	   	    v[i]-=10;
	 	   	}
	 	   }
	 }
	 	int i = 32768;
	 	int flag = 0;
	 	while(i--){
	 		if(v[i] != 0 && !flag){
	 			 flag = 1;
	 		}
	 		if(flag)
	 		  cout <<v[i];
	 	}
	 	cout <<"\n";
}

