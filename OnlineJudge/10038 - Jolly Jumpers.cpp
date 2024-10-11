#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    while(cin >> n) {
        
        int arr[n] = {}; // 1 ~ N-1
        
        int n2 = n-1;
        int a, b;
        cin >> a;
        
        int count = 0;
        for(int i = 0;i<n-1;i++) {
            cin >> b;
            int z = abs(a-b);
            if(arr[z] == 0) {
                arr[z] = 1;
                count++;
            }
            a = b;
        }
        
        cout << (n-1 == count ? "Jolly\n" : "Not jolly\n");
    }
}
