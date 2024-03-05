#include <iostream>

using namespace std;

int main() {
	size_t drink,b,c;
	while(cin >> drink >> b >> c){
		size_t cap = drink , bottle = drink;
		while (bottle >= b || cap >= c) {
		 	size_t thisTime = bottle/b + cap/c;
		 	  
		 	bottle %= b;
		 	cap %= c;
		 	  
		 	drink += thisTime;
		 	cap += thisTime;
		 	bottle += thisTime;
		}
		cout << drink <<" "<<bottle<<" "<<cap <<"\n";
	} 
}
