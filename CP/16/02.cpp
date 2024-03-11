#include <bits/stdc++.h>

using namespace std;

int main() {
	char c;
	cout << "Offset                      Bytes                           Characters\n------  -----------------------------------------------  ----------------";
  
  string s;
	while(cin.get(c)) {
		 s+=c;
	}
	
	int line = 0;
	while(1) {
		 if(line >= s.length())
		   break;
		 string s2;
		 printf("\n%06X ",line);
		 for(int i = 0;i<16;i++) {
		   
		   char c = s[line];
		   if(c) {
		   	 s2+= isprint(c) ? c :'.';
		    printf(" %02X", c);
		 	 } else printf("   ");
		   line++;
		 }
		 cout << "  "<<s2;
	}
	cout << "\n";
}
