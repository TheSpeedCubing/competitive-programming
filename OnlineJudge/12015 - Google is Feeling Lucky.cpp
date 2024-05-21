#include <bits/stdc++.h>

using namespace std;
int main() {
    int T,score;
    cin >> T;
    string s;
    
    vector<string> c;
    for(int t = 1;t<=T;t++) {
    	  cout << "Case #"<<t<<":\n";
        int max = -1;
        for(int i = 0;i<10;i++) {
            cin >> s >> score;
            if(score >= max) {
                if(score > max) {
                    c.clear();
                }
                max = score;
                c.push_back(s);
            }
        }
        
        for(string s : c) {
            cout << s <<"\n";
        }
    }
}
