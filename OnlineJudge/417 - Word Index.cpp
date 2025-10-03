#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int arr[5][128];
    
    // L1
    for(char c = 'a'; c <= 'z'; c++) {
        arr[0][c] = c - 'a' + 1;
    }
    
    // L2 ~ 5
    for(int l = 1; l <= 4; l++) {
                              // z, y, x, w
        arr[l]['a'] = arr[l-1]['z' - l + 1] - arr[l-1]['a'];
        for(char c = 'b'; c <= 'z'; c++) {
                                            // z, y, x, w
            arr[l][c] = arr[l][c-1] + arr[l-1]['z' - l + 1] - arr[l-1][c];
        }
    }
    
    string s;
    while(cin >> s) {
        int sum = 0;
        char mx = 0;
        for(int i = 0;i<s.length();i++) {
           if(s[i] <= mx) {
               sum = 0;
               break;
           } else mx = s[i];
           sum += arr[s.length()-i-1][s[i]]; 
        }
        cout << sum << "\n";
    }
}

/*
int arr[6][128]; // 表
------
(1)

a 1
b 2
c 3
...
z 26

建表
for i = a, i++ to z, j = 1, j++
 arr[1][i] = j
------
(2)

ab 25 + b(1) = 27
ac 25 + c(1) = 28
...
az 25 + z(1) = 51
bc 25 + 24 + c(1) = 52
...
yz = 25 + 24 +... + 1 + z(1) = 351

所以，
a(2) = 25
b(2) = 25 + 24
c(2) = 25 + 24 + 23
...
y(2) = 25 + 24 + ... + 1

建表
arr[2][a] = z(1) - a(1)
for i = b, i++ to y
  arr[2][i] = arr[2][i-1] + arr[1][z] - arr[1][i]
------
(3)
abc = 1~24 + bc = 352
...
bcd = 1~24 + 1~23 + cd = ???
...

所以
a(3) = 1~24
// 也就是 y(2) - a(2)
b(3) = 1~24 + 1~23
// 也就是 a(3) + y(2) - b(2)
c(3) 
// 也就是 b(3) + y(2) - c(2)
...

建表！
arr[3][a] = y(2) - a(2)
for i = b, i++ to x
  arr[3][i] = arr[3][i-1] + arr[2][y] - arr[2][i]

發現了嗎，二層跟三層算法一模一樣
所以：

四層
arr[4][a] = x(3) - a(3)
for i = b, i++ to w
  arr[4][i] = arr[4][i-1] + arr[3][x] - arr[3][i]
五層
arr[5][a] = w(4) - a(4)
for i = b, i++ to v
  arr[5][i] = arr[5][i-1] + arr[4][w] - arr[4][i] 

例子：
agl
= arr[3][a] + arr[2][g] + arr[1][l]
vwxyz
= arr[5][v] + arr[4][w] + arr[3][x] + arr[2][y] + arr[1][z]
*/
