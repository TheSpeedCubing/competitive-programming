#include <iostream>
using namespace std;

double ptx, pty, v1x, v1y, v2x, v2y, v3x, v3y;
double sign(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y) {
    return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

int main() {
    while (cin>> v1x>> v1y>> v2x>>v2y>> v3x>> v3y>>ptx>> pty) {
        double d1 = sign(ptx, pty, v1x, v1y, v2x, v2y), d2 = sign(ptx, pty, v2x, v2y, v3x, v3y),d3 = sign(ptx, pty, v3x, v3y, v1x, v1y);
        cout<<((((d1 <= 0) || (d2 <= 0) || (d3 <= 0)) && ((d1 >= 0) || (d2 >= 0) || (d3 >= 0))) ? "No\n" : "Yes\n");
    }
}