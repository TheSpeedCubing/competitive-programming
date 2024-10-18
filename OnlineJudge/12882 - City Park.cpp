#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int b, a1, a2, id;
};

struct Block {
	int x, y, w, h, id;
};

Block blocks[50001];

//Union Find
int parent[50001]; //unions

int find(int id) {
	if(parent[id] != id) {
		return parent[id] = find(parent[id]);
	}
	return id;
}

void ufunion(int id1, int id2) {
	int r1 = find(id1);
	int r2 = find(id2);

	if(r1 != r2) { //merge
		if(r1 < r2) {
			parent[r1] = r2;
		} else {
			parent[r2] = r1;
		}
	}
}
int main() {
	int n;
	int x,y,w,h;
	while(cin >> n) {
		
		vector<Edge> edgeHor;
		vector<Edge> edgeVer;

		for(int id = 0;id < n;id++) {
			cin >> x >> y >> w >> h;

			parent[id] = id;

			blocks[id] = {x,y,w,h,id};
			
			edgeHor.push_back({y,x,x+w,id});
			edgeHor.push_back({y+h,x,x+w,id});
			edgeVer.push_back({x,y,y+h,id});
			edgeVer.push_back({x+w,y,y+h,id});
		}

		auto sorting = [](Edge e1, Edge e2) {
			if(e1.b == e2.b) {
				return e1.a1 < e2.a1;
			}
			return e1.b < e2.b;
		};

		sort(edgeHor.begin(),edgeHor.end(), sorting);
		sort(edgeVer.begin(),edgeVer.end(), sorting);

        for(int i = 0;i < edgeHor.size();i++) {
			for(int j = i + 1; j < edgeHor.size();j++) {
				if(edgeHor[i].b != edgeHor[j].b) {
					break;
				}
				if(edgeHor[i].a2 >= edgeHor[j].a1) {
					ufunion(edgeHor[i].id, edgeHor[j].id);
				}
			}
		}

        for(int i = 0;i < edgeVer.size();i++) {
			for(int j = i + 1; j < edgeVer.size();j++) {
				if(edgeVer[i].b != edgeVer[j].b) {
					break;
				}
				if(edgeVer[i].a2 >= edgeVer[j].a1) {
					ufunion(edgeVer[i].id, edgeVer[j].id);
				}
			}
		}

		map<int,long long> size;
		long long maxsize = 0;
		for(int i = 0;i<n;i++) {
			int r = find(i);
			size[r] += blocks[i].w * blocks[i].h;
			maxsize = max(maxsize, size[r]);
		}

		cout << maxsize <<"\n";
	}
}
