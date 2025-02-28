#include <bits/stdc++.h>

using namespace std;

int main() {
	string s1,s2,s3,s4,s5;
	cin >> s1 >> s2 >> s3 >> s4;
	ifstream dict(s1);
	
  char b1,b2;
  
	map<int,string> m;
	map<string,int> m2;
	
	int i = 0;
	
	while(dict >> s1) {
		m[i++] = s1;
		m2[s1] = i;
	}
	
	ifstream src(s3);
	if(s2 == "decompress") {
    while (src.read(&b1, 1)) {
        if(b1 >> 7) {
        	 src.read(&b2,1);
        	 string result = m[((b1 & 63) << 8) + (b2&255)];
        	 if(b1 & 64) {
        	 	 result[0] = toupper(result[0]);
        	 }
        	 cout << result;
        } else {
          cout << b1;
        }
    }
	} else {
		string s, origin;
	  ofstream write(s4,ios::binary);
		while(1) {
			bool result = !src.read(&b1,1);
			bool check = result;
			
			if(!result && isalpha(b1)) {
				 s += tolower(b1);
				 origin += b1;
			} else {
				 check = 1;
			}
			
			if(check) {
				 if(m2[s]) {
				 	 short ss = -32768 + (isupper(origin[0]) << 14) + m2[s] - 1;
				   
				   write << (char)(ss >> 8) << (char)(ss & 255);
				 } else {
				   write << origin;
				 }
				 if(!result)
				   write << b1;
				 origin = "";
				 s = "";
			}
			if(result) {
				break;
			}
		}
		write.close();
	  ifstream read(s4);
	  int i = 0;
		while(read.read(&b1,1)) {
			printf("%s%02X",(i % 16 ? " " : (i ? "\n" : "")),b1 & 0xFF);
			i++;
		}
		cout <<"\n";
	}
}
