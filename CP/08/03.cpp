#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
    while(getline(cin,s)) {
	    int cnt[128] = {};
    	for(char c : s)
    	 	cnt[tolower(c)]++;
    	 	    
        for(char i='a';i<='z';i++) {
    	 	cout << *new string(cnt[i], i);
    	}
    	cout <<"\n";
    }
}
