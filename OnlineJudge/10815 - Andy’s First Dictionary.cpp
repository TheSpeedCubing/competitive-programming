#include<bits/stdc++.h>

using namespace std;

int main() {
    
    set<string> words;
    
    string s;
    char c;
    
    
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            s += tolower(c);
        } else {
            words.insert(s);
            s = "";
        }
    }
      
    words.erase("");
    for(string w : words) {
        cout << w << "\n";
    }
}
