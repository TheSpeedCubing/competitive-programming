#include <bits/stdc++.h>

using namespace std;

int n;

bool arr[33] = 

{0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0};

bool isPrime(int i) {
    return arr[i];
}

bool visited[32] = {};
int result[32] = {};

void dfs(int i) {
    if(i == n) {
        if (isPrime(result[0] + result[n-1])) {
            for(int i = 0;i<n;i++) {
                cout << result[i] << (i == n - 1 ? "\n" : " ");
            }
        }
    }
    for(int j = 2; j <= n; j++) {
        if(!visited[j] && isPrime(result[i-1] + j)) {
            visited[j] = true;
            result[i] = j;
            dfs(i + 1);
            visited[j] = false;
        }
    }
}

int main() {
    int t = 0;
    while(cin >> n) {
        if(t++) cout << "\n";
        cout << "Case " << t << ":\n";
        memset(visited, false, sizeof(visited));
        memset(result, false, sizeof(result));
        result[0] = 1;
        visited[0] = 1;
        dfs(1);
    }
}
