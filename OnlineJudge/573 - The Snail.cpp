#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, U, D, F;
  while (cin >> H >> U >> D >> F && H) {
    H *= 100;
    U *= 100;
    D *= 100;

    int loc = 0;
    int fatigue = 0;
    int day = 0;

    bool success = false;
    while (true) {
      day++;

      loc += max(0,(U - fatigue));

      if (loc > H) {
        success = true;
        break;
      }
      
      loc -= D;

      if (loc < 0) {
        success = false;
        break;
      }
      fatigue += F * U / 100;
    }
    cout << (success ? "success" : "failure") << " on day " << day << "\n";
  }
}
