#include <bits/stdc++.h>

using namespace std;

int cnt(int i) {
    int b = 0;
    for(char c : bitset<32>(i).to_string()) {
        if(c == '1')
            b++;
    }
    return b;
}

int main() {
    int t;
    string n;
    cin >> t;
    
    while(t--) {
        cin >> n;
        cout << cnt(stoi(n)) << " " << cnt(stoi("0x"+n, nullptr, 16)) << "\n";
    }
}