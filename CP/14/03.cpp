#include <stack>
#include <iostream>

using namespace std;

int main() {
	string s;
	while(cin >> s){
	  stack<int> v;
	  v.push(1);
	  int cut = 0,  max = 0, maxcut;
	  for(char c : s) {
			 if(c == 49) {
			 	  cut++;
			 	  int x = v.top() + 1;
			 	  if(x > max) {
			 	     max = x; 
			 	     maxcut = cut;
			 	  }
			 	  v.pop();
			   	v.push(x);
			   	v.push(x);
			 } else {
			 	  v.pop();
			 }
	  }
	  cout << maxcut <<"\n";
	}
}
