#include <bits/stdc++.h>

using namespace std;

unsigned char data[32768] = {};
unsigned char* p = data;

int n;

template<typename T>
void check(T* p2, const char* c) {
    for(int i = 0; i < n; ++i) {
        scanf(c, p2++);
    }
    p+=n*sizeof(T);
}

int main() {

    string s;

    while(cin >> s >> n) {
        cin.ignore();
        if(s == "int") {
            check((int*)p, "%d");
        }
        if(s == "short") {
            check((short*)p, "%d");
        }
        if(s == "char") {
            check((char*)p, "%d");
        }
        if(s == "float") {
        	  check((float*) p, "%f");
        }
        if(s == "double") {
        	  check((double*) p, "%lf");
        }
        if(s == "string") {
            while(n--) {
                string str;
                getline(cin, str);
                for(char c : str) {
                    *p++ = c;
                }
                p++;
            }
        }
        if(s == "offset") {
            while(n--) {
            	 *p++ = '\0';
            }
        }
    }
    
   unsigned char* p2 = data;
   int i = 0, flag = 0;
	 while(p2 < p) {
	 	  if(!(i%16))
	 	    printf("%s%04d", (flag++ ? "\n" : "" ),i);
	 	  printf(" %02X",*p2++);
	 	  i++;
	 }

    cout << "\n\nTotal " << i << " bytes.\n";
}
