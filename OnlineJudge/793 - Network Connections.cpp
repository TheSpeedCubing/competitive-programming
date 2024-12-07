#include <bits/stdc++.h>

using namespace std;

map<int,int> parent; //unions

int find(int i) {
	if(parent[i] != i) {
		return parent[i] = find(parent[i]);
	}
	return i;
}

void un(int a, int b) {
	int r1 = find(a);
	int r2 = find(b);

	if(r1 != r2) { //merge
		if(r1 < r2) {
			parent[r1] = r2;
		} else {
			parent[r2] = r1;
		}
	}
}

int main() {
    int t;
    cin >> t;
    
    int f = 0;
    while(t--) {
        if(f++) cout << "\n";
        int success = 0, fail = 0;
        int n;
        cin >> n;
        
        cin.ignore();
        
        char c;
        int a, b;
        
        for(int i = 0;i<=n;i++) {
            parent[i] = i;
        }

        while(1) {
            if((c = getchar()) == EOF || c == '\n') {
                break;
            }
            cin >> a >> b;
            if(c == 'c') {
                un(a, b);
            } else if(c == 'q') {
                if(find(a) == find(b)) {
                    success++;
                } else fail++;
            }
            cin.ignore();
        }
        cout << success << "," << fail <<"\n";
    }
}
