#include <bits/stdc++.h>

using namespace std;

struct E {
    char c;
    int n;
};

int getLastIndex(vector<E> v, int n) {
    bool arrived = false;
    int i = 0;
    for (; i < v.size(); i++) {
        if (v[i].n == n) {
            arrived = true;
        }
        if (arrived && v[i].n != n) {
            break;
        }
    }
    return i - 1;
}

int getFirstIndex(vector<E> v, int n) {
    int i = 0;
    char c = 'Z' + 1;
    for (; i < v.size(); i++) {
        if (v[i].n == n) {
            return i;
        }
    }
}

void f() {
    int n;
    cin >> n;
    cin.ignore();
    vector<int> cnt('Z' + 1, -1);
    string s;
    getline(cin, s);
    for (char i = 'A'; i < 'A' + n; i++) {
        cnt[i] = 0;
        for (char c : s) {
            if (c == i) {
                cnt[c]++;
            }
        }
    }
    vector<E> v;
    map<int, int> m; // n -> len

    for (int i = 'A'; i <= 'Z'; i++) {
        if (cnt[i] != -1) {
            v.push_back({(char) i, cnt[i]});
            if (!m.count(cnt[i])) {
                m[cnt[i]] = 1;
            } else {
                m[cnt[i]]++;
            }
        }
    }

    sort(v.begin(), v.end(), [](E a, E b) {
        if (a.n != b.n) {
            return a.n > b.n;
        } else {
            return a.c < b.c;
        }
    });

    vector<char> left, right;
    while (1) {
        if (v.size() == 0) {
            break;
        }
        if (v.size() == 1) {
            left.push_back(v[0].c);
            break;
        }
        if (m[v[0].n] > 1) {
            char ll = v[0].c;
            int r = getLastIndex(v, v[0].n);
            char rr = v[r].c;
            left.push_back(min(ll, rr));
            right.push_back(max(ll, rr));
            v.erase(v.begin());
            v.erase(v.begin() + r - 1);
            m[v[0].n] -= 2;
        } else {
            char ll = v[0].c;
            int r = getLastIndex(v, v[1].n);
            int rf = getFirstIndex(v, v[1].n);
            if (ll > v[rf].c) {
                r = rf;
            }
            char rr = v[r].c;
            left.push_back(min(ll, rr));
            right.push_back(max(ll, rr));
            v.erase(v.begin());
            v.erase(v.begin() + r - 1);
            m[v[0].n]--;
            m[v[1].n]--;
        }
    }

    for (int i = 0; i < left.size(); i++) {
        if (i) cout << " ";
        cout << left[i];
    }
    for (int i = right.size() - 1; i >= 0; i--) {
        cout << " " << right[i];
    }
    cout << "\n";
    for (int i = 0; i < left.size(); i++) {
        if (i) cout << " ";
        cout << cnt[left[i]];
    }
    for (int i = right.size() - 1; i >= 0; i--) {
        cout << " " << cnt[right[i]];
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        f();
    }
}