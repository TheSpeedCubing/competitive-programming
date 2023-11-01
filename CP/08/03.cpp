#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
    while(getline(cin,s)) {
	    int cnt[128] = {0};
    	 for(char c : s)
    	 	  cnt[tolower(c)]++;
    	 	    
    	 for(int i='a';i<='z';i++)
    	 	  while(cnt[i]--)
    	 	    cout << (char) i;
    	 cout <<"\n";
    }
}