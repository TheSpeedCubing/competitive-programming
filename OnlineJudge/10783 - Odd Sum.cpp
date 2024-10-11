#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, a, b;
    cin >> T;
    for(int t = 1;t<=T;t++) {
        cin >> a >> b;
        if(a % 2 == 0) {
            a++;
        }
        
        int sum = 0;
        while(a <= b) {
            sum += a;
            a += 2;
        }
        cout << "Case " << t << ": " << sum << "\n";
    }
}
