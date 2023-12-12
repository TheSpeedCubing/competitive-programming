#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1;t<=T;t++) {
        string s;
        cin >> s;
        char n[1024][1024] = {0};
        int limit[1024] = {0};
        int maxLevel = 0;
        int minLevel = 1024;
        int level = 500;
        for(int i = 1;i <= s.length();i++) {
            char c = s[i-1];
            if(c == 'R')
                n[i][level] = '/';
            if(c =='C')
                n[i][level] = '_';
            if(c=='F') {
                level--;
                n[i][level]= '\\';
            }
            limit[level] = i;
	          maxLevel = max(maxLevel,level);
	          minLevel = min(minLevel,level);
	          if(c == 'R')
	          	level++;
        }
        
        cout <<"Case #"<<t<<":\n";
        for (int j = maxLevel;j>=minLevel;j--) {
            cout <<"|";
            for (int i = 0;i<=limit[j];i++)
                cout << (n[i][j]?n[i][j]:' ');
            cout <<"\n";
        }
        cout <<"+";
        for (int i = 0;i<s.length()+2;i++)
            cout <<"-";
        cout <<"\n\n";
    }
}
