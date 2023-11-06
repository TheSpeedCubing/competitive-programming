#include <iostream>

#include <string>

using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
  	string result = to_string(a/b);
  	if(a%b) {
      result += ".";
      a %= b;
      int n[32768] = {0}, i = 0, len = result.length();
      
      while (1) {
      	
        a *= 10;
        
        int breakFlag = 0, j = 0;
        
        for(;j<32768;j++) {
        	if(n[j] == a) {
        		breakFlag = 1;
        		result = result.substr(0,len+j) + "(" + result.substr(len+j) + ")";
        		break;
        	}
        }
        
        if(breakFlag)
          break;
          
        result += to_string(a / b);
        
        n[i] = a;
        i++;
        
        a %= b;
        if (!a) {
          result += "(0)";
          break;
        }
      }
  	} else result += ".(0)";
  	cout <<result<<"\n";
  }
}