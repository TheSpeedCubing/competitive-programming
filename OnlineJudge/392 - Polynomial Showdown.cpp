#include <bits/stdc++.h>

using namespace std;

int main()
{
	 while(1){
	 	  int n;
	 	  bool printed = 0;
	 	  for(int i = 8;i>=0;i--){
	 	  	 if(!(cin >> n))
	 	  	   exit(0);
	 	  	 if(!n)
	 	  	   continue;
	 	  	 
	 	  	 if(printed)
	 	  	   cout <<" ";
	 	  	 
	 	  	 if(!printed) {
	 	  	 	 if(i == 0) {
	 	  	 	 	 cout << n;
	 	  	 	 } else if(n == -1)
	 	  	     cout <<"-";
	 	  	   else if(n != 1){
	 	  	   	 cout << n;
	 	  	   }
	 	  	 } else {
	 	  	 if(n > 0){
	 	  	 	if(printed)
	 	  	 	  cout <<"+ ";
	 	  	 }
	 	  	 if(n == -1) {
	 	  	     cout <<"- ";
	 	  	 }
	 	  	 if(n < -1){
	 	  	 	if(printed)
	 	  	 	  cout <<"- ";
	 	  	 }
	 	  	 if(n != 1 && n != -1 || i == 0)
	 	  	 cout << abs(n);
	 	  	 }
	 	  	 if(i > 0)
	 	  	   cout << "x";
	 	  	 if (i > 1)
	 	  	   cout<<"^"<<i;
	 	  	 printed = 1;
	 	  }
	 	  if(!printed)
	 	    cout << 0;
	 	  cout <<"\n";
	 }
}
