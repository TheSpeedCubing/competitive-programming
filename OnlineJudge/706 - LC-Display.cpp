#include <bits/stdc++.h>

using namespace std;


char h = '-';
char v = '|';
char b = ' ';

// 7 segments, 0 ~ 9
char seg[10][7] = {
    {v, v, h, b, h, v, v},
    {b, b, b, b, b, v, v},
    {b, v, h, h, h, v, b},
    {b, b, h, h, h, v, v},
    {v, b, b, h, b, v, v},
    {v, b, h, h, h, b, v},
    {v, v, h, h, h, b, v},
    {b, b, h, b, b, v, v},
    {v, v, h, h, h, v, v},
    {v, b, h, h, h, v, v}
};

int s;
string n;

void hor(int index) {
    int f = 0;
    for(char c : n) {
        if(f++) cout << " ";
        
        cout << " " << string(s, seg[c-'0'][index]) << " ";
    }
    
    cout << "\n";
}

void ver(int l, int r) {
    int t = s;
    while(t--) {
        
        int f = 0;
        for(char c : n) {
            if(f++) cout << " ";
            
            cout << seg[c-'0'][l] << string(s, ' ') << seg[c-'0'][r];
        }
        cout << "\n";
    }
}

int main() {
    while(cin >> s >> n && s) {
        hor(2);
        ver(0, 5);
        hor(3);
        ver(1, 6);
        hor(4);
        cout << "\n";
    }
}