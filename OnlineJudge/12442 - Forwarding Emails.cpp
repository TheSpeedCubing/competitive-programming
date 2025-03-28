#include <bits/stdc++.h>

using namespace std;

vector<int> target;

vector<bool> visited;
vector<bool> dfsVisited; // visited for DFS

int cnt = 1;
int dfsCnt = 1;

void dfs(int i) {
    visited[i] = true;
    dfsVisited[i] = true;
    dfsCnt++;
    if (!dfsVisited[target[i]]) 
       dfs(target[i]);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        
        target.resize(n+1);
      
        visited.assign(n+1, false);
        cnt = 1;
      
        for(int i = 0;i<n;i++) {
            int a, b;
            cin >> a >> b;
            target[a] = b;
        }
        
        int minId = target[1];
        
        for (int i = 1;i<=n;i++) {
            if (visited[i]) {
                continue;
            }
          
            dfsVisited.assign(n+1, false);
            dfsCnt = 1;

            dfsVisited[i] = true;
            
            dfs(target[i]);
            if (dfsCnt > cnt || (dfsCnt == cnt && i < minId)) {
                minId = i;
                cnt = dfsCnt;
            }
        }
        cout << "Case " << t << ": " << minId << "\n";
    }
}
