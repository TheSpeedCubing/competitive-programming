#include <bits/stdc++.h>

using namespace std;
int main()
{
    double x[4], y[4];
    int a, b, c;
    while(cin >>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3]) {
        if(x[0]==x[2] && y[0]==y[2]) {
            a=0; b=1; c=3;
        }
        else if(x[0]==x[3] && y[0]==y[3]){
            a=0; b=1; c=2;
        }
        else if(x[1]==x[2] && y[1]==y[2]){
            a=1; b=0; c=3;
        }
        else {
            a=1; b=0; c=2;
        }
        printf("%.3lf %.3lf\n", x[b] + x[c] - x[a], y[b] + y[c] - y[a]);
    }
}
