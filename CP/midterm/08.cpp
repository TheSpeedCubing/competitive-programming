#include <iostream>

using namespace std;

int main()
{
   string s;
   while(cin >> s){
   	int a = 0,b=0;
   	for(int i = 0;i<s.length();i++){
   		if(i%2) {
   			b+=s[i]-48;
   		} else a+=s[i]-48;
   	}
   	cout << ((a-b < 0) ? b-a:(a-b))<<"\n";
   }
}


