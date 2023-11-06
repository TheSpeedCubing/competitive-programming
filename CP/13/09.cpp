#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	while(cin >> a>>b>>c){
		 int bottle = a , cap = a , drink = a;
		do {
		 	  int thisTime = bottle/b + cap/c;
		 	  
		 	  bottle = bottle%b+thisTime;
		 	  cap =  cap%c+thisTime;
		 	  
		 	  drink+=thisTime;
		 } while (bottle >= b || cap >= c);
		 cout << drink <<" "<<bottle<<" "<<cap <<"\n";
	} 
}
