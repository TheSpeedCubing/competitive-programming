#include <bits/stdc++.h>

using namespace std;

set<char> mappings[128];

bool visited[128];

bool dfs(char start, char end) {
    visited[start] = true;
    if(start == end) {
        return true;
    }
    
    for(char c : mappings[start]) {
        if(!visited[c]) {
            if(dfs(c, end)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    int a, b;
    while(cin >> a >> b) {
        for(int i = 0;i<128;i++) {
            mappings[i].clear();
        }
        
        cin.ignore();
        char c1, c2;
        
        for(int i = 0;i<a;i++) {
            cin >> c1 >> c2;
            cin.ignore();
            mappings[c1].insert(c2);
        }
        
        string s1, s2;
        for(int i = 0;i<b;i++) {
            cin >> s1 >> s2;
            if(s1.length() != s2.length()) {
                cout << "no\n";
                continue;
            }
            
            bool t = true;
            for(int j = 0;j<s1.length();j++) {
                if(s1[j] == s2[j]) 
                    continue;
                    
                memset(visited, false, sizeof(visited));
                if(!dfs(s1[j], s2[j])) {
                    t = false;
                    break;
                }
            }
            if(t) 
                cout << "yes\n";
            else cout << "no\n";
        }
    }
}
