#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x;
    while (cin >> x) {
        cin.ignore();
        
        string line;
        getline(cin, line);
        stringstream ss(line);

        vector<long long> f;
        long long c;
        while (ss >> c) {
          f.push_back(c);
        }

        long long sum = 0;
        int deg = f.size() - 1;
        long long xx = 1;

        for (int i = deg - 1; i >= 0; --i) {
            sum += f[i] * (deg - i) * xx;
            xx *= x;
        }

        cout << sum << '\n';
    }
}
