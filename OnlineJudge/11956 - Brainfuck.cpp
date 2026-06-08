#include <bits/stdc++.h>

using namespace std;

int main() {
    int T = 0;
    cin >> T;
    cin.ignore();
    for(int t = 1; t <= T; t++) {
        
        string s;
        getline(cin, s);
        
        int arr[100] = {};
        int index = 0;
        
        for(char c : s) {
            if(c == '>') {
                index++;
                if(index == 100) {
                    index = 0;
                }
            }
            if(c == '<') {
                index--;
                if(index == -1) {
                    index = 99;
                }
            }
            if(c == '+') {
                arr[index]++;
                if(arr[index] == 256) {
                    arr[index] = 0;
                }
            }
            if(c == '-') {
                arr[index]--;
                if(arr[index] == -1) {
                    arr[index] = 255;
                }
            }
        }
        
        cout << "Case " << t << ":";
        for(int i = 0;i<100;i++) {
            printf(" %02X", arr[i]);
        }
        cout << "\n";
    }
}