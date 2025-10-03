/*
1. input n
2. print n
3. if n = 1 then STOP
4. if n is odd then n ←− 3n + 1
5. else n ←− n/2
6. GOTO 2
*/
int f(int n, int cnt) {
    if (n == 1) {
        return cnt;
    }
    if (n % 2 != 0) {
        n = 3 * n + 1;
    } else {
        n = n / 2;
    }
    return f(n, cnt + 1);
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int i, j;
    while(cin >> i >> j) {
        cout << i << " " << j << " ";
        if(i > j) {
            swap(i, j);
        }
        
        int mx = 0;
        while(i <= j) {
            mx = max(mx, f(i, 1));
            i++;
        }
        cout << mx << "\n";
    }

    return 0;
}
