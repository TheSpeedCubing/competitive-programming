#include <bits/stdc++.h>

using namespace std;

int main() {
    
    cout << "PERFECTION OUTPUT\n";
    
    int n;
    while(cin >> n && n) {
        printf("%5d  ", n);
        int sum = 0;
        for(int i = 1;i<n;i++) {
            if(n % i == 0) {
                sum += i;
            }
        }
        if(n == sum) {
            cout << "PERFECT\n";
        } else if(n > sum) {
            cout << "DEFICIENT\n";
        } else {
            cout << "ABUNDANT\n";
        }
    }
    
    cout << "END OF OUTPUT\n";
}
