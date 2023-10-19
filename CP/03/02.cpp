#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int main() {
    string str = "Hello CodingPass!"; 
    for(int i = str.length()-1;i>=0;i--) {
      	for(int j = 0;j<i;j++)
	    	    cout << " ";
	 	    cout << str.substr(i,str.length())<<"\n";
    }
}