#include <bits/stdc++.h>

using namespace std;

struct Edge {
   int a1,a2,b,id;
};

struct Block {
   int x,y,w,h,id;
};

Block blocks[50001]; // id -> block
vector<Edge> edgeHor;
vector<Edge> edgeVer;

//Union-Find Algs
int parents[50001] = {}; //id -> parent
set<int> roots;

int find(int id) {
    if(parents[id] != id) {
        
        //optimize
        parents[id] = find(parents[id]);
        
        return parents[id];
    } else return id;
}

void unionn(int id1, int id2) {
    int p1 = find(id1);
    int p2 = find(id2);
    if(p1 != p2) {
        
        //optimize
        if(p1 < p2) {
            swap(p1,p2);
        }

        parents[p2] = p1;
    }
}

int main() {
    int n;
    int x, y, w, h;
    while(cin >> n) {
        memset(parents,-1,sizeof(parents));
        roots.clear();
        edgeHor.clear();
        edgeVer.clear();
        
        long long maxs = 0;
        
    	for(int id = 0;id<n;id++) {
            cin >> x >> y >> w >> h;
            parents[id] = id;
            blocks[id] = {x,y,w,h,id};
            edgeHor.push_back({x,x+w,y+h,id});
            edgeHor.push_back({x,x+w,y,id});
            edgeVer.push_back({y,y+h,x,id});
            edgeVer.push_back({y,y+h,x+w,id});
        }

        auto lambd = [](Edge e1,Edge e2){
            if(e1.b == e2.b) {
                return e1.a1 < e2.a1;
            }
            return e1.b < e2.b;
        };

        sort(edgeHor.begin(),edgeHor.end(),lambd);
        sort(edgeVer.begin(),edgeVer.end(),lambd);

        int hSize = edgeHor.size();
        for(int i = 0;i<hSize;++i) {
            for(int j = i+1;j<hSize;++j) {
                if(edgeHor[i].b != edgeHor[j].b) {
                    break;
                }
                if(edgeHor[i].a2 >= edgeHor[j].a1) {
                    unionn(edgeHor[i].id, edgeHor[j].id);
                }
            }
        }

        int vSize = edgeVer.size();
        for(int i = 0;i<vSize;++i) {
            for(int j = i+1;j<vSize;++j) {
                if(edgeVer[i].b != edgeVer[j].b) {
                    break;
                }
                if(edgeVer[i].a2 >= edgeVer[j].a1) {
                    unionn(edgeVer[i].id, edgeVer[j].id);
                }
            }
        }

        map<int,long long> size;
        for(int i = 0;i<n;i++) {
            int root = find(i);
            size[root] += blocks[i].w * blocks[i].h;
            maxs = max(size[root],maxs);
        }
        
        cout << maxs << "\n";
    }       
}
