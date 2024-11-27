#include <bits/stdc++.h>

using namespace std;

int f, heal;
string name;

int main() {
  
  while(cin >> name) {
    if(f++) cout <<"\n";
		
    cin >> heal;

    int mm[101] = {},
        movement = 0,
        minimum = 2147483647;
        
    for(int i = 0;i<heal;i++){
      cin >> mm[i];
      movement += mm[i];
      minimum = min(minimum, movement);
    }
    
    minimum = abs(minimum);
	  
    for(int i=0;i<=heal;i++) {
      cout << *new string(minimum,'-') << name << "\n";
       minimum += mm[i];
    }
  }
}
