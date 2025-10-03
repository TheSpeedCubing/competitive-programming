#include <bits/stdc++.h>

using namespace std;

int f(int dist, vector<int> v) {
    int days = 1, sum = 0;
    for (int i : v) {
        if (sum + i > dist) {
            days++;
            sum = 0;
        }
        sum += i;
    }
    return days;
}

int main() {
    
    int N, K;

    while (cin >> N >> K) {
        vector<int> v(N + 1);
        
        int mx = 0;
        int sum = 0;
        for (int i = 0; i <= N; i++) {
            cin >> v[i];
            mx = max(mx, v[i]);
            sum += v[i];
        }
        
        int low = mx;
        int high = sum;

        while (low < high) {
            int mid = (low + high) / 2;
            if (f(mid, v) <= K + 1) high = mid;
            else low = mid + 1;
        }

        cout << low << "\n";
    }
}
