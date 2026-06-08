#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    
    int t = 0;
    while(getline(cin, s) && s != "end") {
        vector<char> stacks;
        for(char c : s) {
            
            bool foundStack = false;
            for(int i = 0; i < stacks.size(); i++) {
                if(stacks[i] >= c) {
                    foundStack = true;
                    stacks[i] = c;
                    break;
                }
            }
            
            if(!foundStack) {
                stacks.push_back(c);
                continue;
            }
        }
        
        cout << "Case " << ++t << ": " << stacks.size() << "\n";
    }
}