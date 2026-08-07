#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> r;
vector<int> parity;

vector<int> parent2;
vector<int> r2;
vector<int> parity2;

//find the root of x
int find(int x) {
    if(parent[x] != x) {
        int p = parent[x];
        parent[x] = find(parent[x]);
        parity[x] ^= parity[p]; // update
    }
    return parent[x];
}

//union a and b
bool unionSet(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);

    if(r1 == r2) {
        return (parity[a] != parity[b]);
    }
    
    if(r[r1] < r[r2]) {
        parent[r1] = r2;
        parity[r1] = parity[a] ^ parity[b] ^ 1; // update
    } else if(r[r1] > r[r2]) {
        parent[r2] = r1;
        parity[r2] = parity[a] ^ parity[b] ^ 1; // update
    } else {
        parent[r2] = r1;
        parity[r2] = parity[a] ^ parity[b] ^ 1; // update
        r[r1]++;
    }
    return true;
}

int main() {
    int a, b;

    int n, m;
    cin >> n >> m;

    for(int i = 0;i<n;i++) {
        parent.push_back(i);
        r.push_back(0);
        parity.push_back(0);
    }
    
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        unionSet(a, b);
    }
        
    // backup
    parent2 = parent;
    r2 = r;
    parity2 = parity;
    
    int p, k;
    cin >> p >> k;
    for(int id = 1; id <= p; id++) {
        
        // restore
        parent = parent2;
        r = r2;
        parity = parity2;

        bool f = true;
        for(int i = 0; i < k; i++) {
            cin >> a >> b;
            if(!unionSet(a, b)) {
                f = false;
            }
        }

        if(!f)
            cout << id << "\n";
    }
}
