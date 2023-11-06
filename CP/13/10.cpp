#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
	 int a,b,flag=1;
	 while(cin >> a >> b){
	 	if(flag)
	 	  flag=0;
	 	else cout <<"\n";
	 	   for(int i = 0;i<pow(2,a);i++){
	 	   	   string s = bitset<16>(i).to_string().substr(16 - a);
	 	   	   int copy = a , cnt = 0;
	 	   	   while(copy--)
	 	   	   	 cnt += s[copy] - 48;
	 	   	   if(cnt==b)
	 	   	     cout << s <<"\n";
	 	   }
	 }
}
