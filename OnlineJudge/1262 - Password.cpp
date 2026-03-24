#include <bits/stdc++.h>

using namespace std;

bool dbg = 0;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int k; 
        cin >> k;
        
        vector<char> result[5];
        
        set<char> buf[5];
        set<char> buf2[5];
        
        char c;
        for(int i = 0;i<6;i++) {
            for(int j = 0;j < 5 ; j++) {
                cin >> c;
                buf[j].insert(c);
            }
        }
        
        for(int i = 0;i<6;i++) {
            for(int j = 0;j < 5 ; j++) {
                cin >> c;
                buf2[j].insert(c);
            }
        }
        
        int possibilities = 1;
        for(int i = 0;i<5;i++) {
            for(char c : buf[i]) {
               if(buf2[i].count(c)) {
                   result[i].push_back(c);
               }   
            }
            sort(result[i].begin(), result[i].end());
            possibilities *= result[i].size();
        if(dbg) {
            for(char c : result[i]) {
                cout << c;
            }
            cout << "\n";
        }
        } 
        
        if(dbg)
        cout << possibilities << "\n";
        
        if(k > possibilities) {
            cout << "NO\n";
            continue;
        }
        
        int n = (k-1) / (possibilities / result[0].size());
        cout << result[0][n];
        k -= possibilities * n / result[0].size();
        possibilities /= result[0].size();
        
        n = (k-1) / (possibilities / result[1].size());
        cout << result[1][n];
        k -= possibilities * n / result[1].size();
        possibilities /= result[1].size();
        
        n = (k-1) / (possibilities / result[2].size());
        cout << result[2][n];
        k -= possibilities * n / result[2].size();
        possibilities /= result[2].size();
        
        n = (k-1) / (possibilities / result[3].size());
        cout << result[3][n];
        k -= possibilities * n / result[3].size();
        possibilities /= result[3].size();
        
        n = (k-1) / (possibilities / result[4].size());
        cout << result[4][n] << "\n";
        k -= possibilities * n / result[4].size();
        possibilities /= result[4].size();
    }
    
}
