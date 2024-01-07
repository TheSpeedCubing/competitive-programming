#include <bits/stdc++.h>

using namespace std;

vector<int> result;
vector<int> arr[101];
bool visited[101], route[101];

void dfs(int i) {
	visited[i] = true;
	for(int j : arr[i])
	  if(!visited[j])
	     dfs(j);
	 result.push_back(i);
}

int main()
{
	int n,m,i,j;
	while(cin >> n >> m && (n || m)) {
		result.clear();
		fill(arr,arr+101,vector<int>());
		fill(route,route+101,false);
		fill(visited,visited+101,false);
		
    while(m--) {
    	cin >> i >> j;
    	arr[i].push_back(j);
    	route[j] = true;
    }
    
    for(int i = 1;i<=n;i++)
      if(!visited[i])
        dfs(i);
     
    for(int i = result.size() -1;i>=0;i--)
      cout << result[i] << (i ? " ":"\n");
	}
}
