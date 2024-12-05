#include <bits/stdc++.h>

using namespace std;

int dfn[101], low[101], parent[101];
bool visited[101], ap[101];
map<int, set<int>> g;
set<int> result;

void addEdge(int u, int v) {
  g[u].insert(v);
  g[v].insert(u);
}

int cnt = 0;
void dfs(int u) {
  int children = 0;

  cnt++;
  dfn[u] = cnt;
  low[u] = cnt;
  visited[u] = true;

  for (int v : g[u]) {
    if (!visited[v]) {
      children++;
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (parent[u] == -1 ? children >= 2 : low[v] >= dfn[u]) {
        result.insert(u);
      }
    } else if (v != parent[u]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

int main() {
  int n;
  while (cin >> n && n) {
    cin.ignore();

    fill_n(parent, 101, -1);
    fill_n(dfn, 101, 0);
    fill_n(low, 101, 0);
    fill_n(visited, 101, false);
    fill_n(ap, 101, false);
    g.clear();
    result.clear();
    cnt = 0;

    string s;
    while (getline(cin, s)) {
      stringstream ss(s);

      int root, i;
      ss >> root;
      if (root == 0) {
        break;
      }
      while (ss >> i) {
        addEdge(root, i);
      }
    }
    dfs(1);
    cout << result.size() << "\n";
  }
}
