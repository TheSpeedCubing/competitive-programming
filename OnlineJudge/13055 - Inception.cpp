#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main() {
	stack<string> stack;
  
  int T;
	cin >> T;
  
	while(T--) {
	  string s;
	  cin >> s;
	  if(s == "Sleep"){
	  	   string name;
	  	   cin >> name;
	  	   stack.push(name);
	  }else if(s == "Kick"){
	  	  if(!stack.empty())
	  	    stack.pop();
	  }else if(s == "Test"){
	  	  if(stack.empty())
	  	    cout << "Not in a dream\n";
	  	  else 
	  	    cout << stack.top()<<"\n";
	  }
	}
}
