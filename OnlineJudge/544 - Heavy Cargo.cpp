#include<bits/stdc++.h>

using namespace std;

struct Edge {
  string a, b;
  int w;
};

map<int, int> parent;
map<int,int> rk;

int find(int i) {
    if(parent[i] != i) {
        return parent[i] = find(parent[i]);
    }
    return i;
}

void un(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if(r1 == r2) {
        return;
    }
    if(rk[r1] < rk[r2]) {
        parent[r1] = r2;
    } else {
        parent[r2] = r1;
    }
    if(rk[r1] == rk[r2]) {
        rk[r1]++;
    }
}

int main() {
    int n, r;
    int t = 1;
    while(cin >> n >> r && n && r) {
        cout << "Scenario #" << t++ <<"\n";
        vector<Edge> edges;
        map<string,int> strToID;
        
        parent.clear();
        rk.clear();
        
        string a, b;
        int x;
        
        int id = 1;
        for(int i = 0;i<r;i++) {
            cin >> a >> b >> x;
            edges.push_back({a,b,x});
            if(!strToID.count(a)) {
                strToID[a] = id++;
            }
            if(!strToID.count(b)) {
                strToID[b] = id++;
            }
        }
        
        for(int i = 1;i<id;i++) {
            rk[i] = 0;
            parent[i] = i;
        }
        
        cin >> a >> b;
        
        //kruskal
        
        sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {
           return e1.w > e2.w; 
        });
        
        vector<Edge> ee;
        for(Edge e : edges) {
            int r1 = find(strToID[e.a]);
            int r2 = find(strToID[e.b]);
            if(r1 != r2) {
                un(strToID[e.a], strToID[e.b]);
                ee.push_back(e);
            }
            if(find(strToID[a]) == find(strToID[b])) {
                cout << e.w << " tons\n";
                break;
            }
        }
        cout <<"\n";
    }
}
