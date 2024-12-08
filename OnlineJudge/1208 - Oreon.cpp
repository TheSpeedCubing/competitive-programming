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
    
    int T;
    cin >> T;
    for(int t = 1;t<=T;t++) {
        int N;
        cin >> N;
        
        //init
        vector<Edge> edges;
        
        rk.clear();
        parent.clear();
        for(int i = 1;i <= N;i++) {
            rk[i] = 0;
            parent[i] = i;
        }
        
        
        int w;
        for(int i = 0;i<N;i++) {
            for(int j = 0;j<N;j++) {
                cin >> w;
                cin.ignore();
                if(i < j && w) {
                    edges.push_back({i, j, w});
                }
            }
        }
        
        //kruskal
        sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) {
            if(e1.w != e2.w)
                return e1.w < e2.w;
            if(e1.a != e2.a)
                return e1.a < e2.a;
            return e1.b < e2.b;
        });
        
        vector<Edge> v;
        for(Edge e : edges) {
           int r1 = find(e.a);
           int r2 = find(e.b);
           if(r1 != r2) {
               v.push_back(e);
               un(r1, r2);
           }
        }
        
        cout << "Case " << t  <<":\n";
        for(Edge e : v) {
            cout << (char) ('A' + e.a) << "-" << (char) ('A' + e.b) <<" "<< e.w <<"\n";
        }
    }
}
