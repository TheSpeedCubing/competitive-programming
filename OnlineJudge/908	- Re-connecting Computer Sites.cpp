#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int a, b, w;
};



map<int,int> parent; //unions
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
	
	if(rk[r1] < rk[r2]) { //merge
		parent[r1] = r2;
	} else {
		parent[r2] = r1;
	}
	
	if(rk[r1] == rk[r2]) {
	    rk[r1]++;
	}
}

int main() {
    int N, K, M;
    int a, b, w;
    
    int f = 0;
    while(cin >> N) {
        if(f++) cout <<"\n";
        
        //init
        vector<Edge> edges;
        rk.clear();
        parent.clear();
        for(int i = 1;i <= N;i++) {
            rk[i] = 0;
            parent[i] = i;
        }
        
        
        //N
        int totalcost = 0;
        for(int i = 1;i < N;i++) {
            cin >> a >> b >> w;
            totalcost += w;
        }
        cout << totalcost << "\n";
        
        //K
        cin >> K;
        for(int i = 0;i < K;i++) {
            cin >> a >> b >> w;
            edges.push_back({a,b,w});
        }
        
        //M
        cin >> M;
        for(int i = 0;i < M;i++) {
            cin >> a >> b >> w;
            edges.push_back({a,b,w});
        }
        
        //kruskal
        sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {
            return e1.w < e2.w; 
        });
        
        int total = 0;
        for(int i = 0;i < M;i++) {
           int r1 = find(edges[i].a);
           int r2 = find(edges[i].b);
           if(r1 != r2) {
               un(r1, r2);
               total += edges[i].w;
           }
        }
        
        cout << total << '\n';
    }
}
