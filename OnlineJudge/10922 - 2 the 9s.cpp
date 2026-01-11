#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    while(cin >> n && n != "0") {
        cout << n;
        int cnt = 0;
        int sum;
        while(1) {
            cnt++;
            sum = 0;
            for(char c : n) {
                sum += (c - '0');
            } 
            if(sum < 10) {
                break;
            }
            n = to_string(sum);
        }
        if(sum == 9) {
            cout << " is a multiple of 9 and has 9-degree " << cnt << ".\n";
        } else {
            cout << " is not a multiple of 9.\n";
        }
    }
}
