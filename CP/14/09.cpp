#include <iostream>

using namespace std;

int main() {
    int dt[16384];

    int seed, n, m, d=0;

    cin >> seed >> n >> m;

    srand(seed);
    int copy2 = m;

    while(copy2--){
        int j=0, cnt=0;
        while(j < n) {
          dt[j] = j+1;
          j++;
        }
        while(j--){
            int y = rand() % (j+1);
            
            cnt += (dt[y] == n - j);
            
            int temp = dt[y];
            dt[y] = dt[j];
            dt[j] = temp;

        }
        d += !cnt;
        cout << cnt << "/" << n << "\n";
    }
    printf("%.4f\n",(double) d/m);
}
