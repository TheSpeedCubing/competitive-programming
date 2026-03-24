#include <bits/stdc++.h>

using namespace std;

int vec[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int h, w;

bool check(string s, vector<vector<char>> v, int i, int j, int vecId) {
    for(int c = 1; c < s.length(); c++) {
        int h2 = i + vec[vecId][0];
        int w2 = j + vec[vecId][1];
        if(h2 < 0 || w2 < 0 || h2 >= h || h2 >= w) {
            return false;
        }
        
        if(tolower(v[h2][w2]) != tolower(s[c])) {
            return false;
        }
        i = h2;
        j = w2;
    }
    return true;
}

pair<int,int> handleStr(string s, vector<vector<char>> v) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(tolower(v[i][j]) == tolower(s[0])) {
                for(int k = 0; k < 8; k++) {
                    if(check(s, v, i, j, k)) {
                        return {i, j};   
                    }
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    cin.ignore();
    cin.ignore();
    
    int f = 0;
    while(t--) {
        if(f++) cout << "\n";
        
        cin >> h >> w;
        
        vector<vector<char>> v(h, vector<char>(w));
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> v[i][j];
            }
        }
        
        int n;
        cin >> n;
        while(n--) {
            string s;
            cin >> s;
        
            auto ans = handleStr(s, v);
            cout << (ans.first + 1) << " " << (ans.second + 1) << "\n";
        }
    }
}