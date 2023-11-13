#include <iostream>

using namespace std;

int main() {
  int a, b, c, r1, r2, r3;
  while (cin >> a >> r1 >> b >> r2 >> c >> r3) {
    int m1 = 0, m2 = 0, m3 = 0;
    while ((m1 * b * c) % a != r1)
      m1++;
    while ((m2 * a * c) % b != r2)
      m2++;
    while ((m3 * a * b) % c != r3)
      m3++;
    cout << (m1 * b * c + m2 * c * a + m3 * a * b) % (a * b * c) << "\n";
  }
}