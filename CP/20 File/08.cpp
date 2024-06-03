#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv)
{
    
    string s,in;
    ifstream file2(argv[2]), file(argv[1]);
    char c;
    while(file2.get(c)) {
    	s += c;
    }
    
    int i = 0;
    
    while(getline(file,in)) {
    	 string placeholder = "<#" + to_string(i) + ">";
    	 size_t pos;
    	 while((pos = s.find(placeholder)) != string::npos) {
       	   s.replace(pos,placeholder.length(),in);
    	 }
     	 i++;
    }
    cout <<s;
}