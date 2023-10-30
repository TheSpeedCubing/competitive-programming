#include <iostream>
using namespace std;

int main() {
	char anotherbufferagain[1024];
    while(cin.getline(anotherbufferagain, 1024)) {
	    int cnt[128] = {0}, i=0;
    	 for(;i<strlen(anotherbufferagain);i++)
    	 	  cnt[tolower(anotherbufferagain[i])]++;
    	 	    
    	 for(i='a';i<='z';i++)
    	 	  while(cnt[i]--)
    	 	    cout << (char) i;
    	 cout <<"\n";
    }
}