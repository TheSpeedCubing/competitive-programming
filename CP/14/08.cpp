#include <iostream>

using namespace std;

int main() {
  int T, s;
  cin >> T;

  while (T--) {
    cin >> s;
    int nums[10000], i = 0;

    while (i < s)
      cin >> nums[i++];

    int max = nums[0],
      dp = max,
      start = 0,
      end = 0,
      temp = 0,

      len = 0,
      minlen = 0;
    for (i = 1; i < s; i++) {
      if (dp > 0) {
        len++;
        dp += nums[i];
      } else {
        len = 0;
        dp = nums[i];
        temp = i;
      }
      
      if((dp == max && minlen > len) || dp > max) {
        	minlen = len;
          max = dp;
          start = temp;
          end = i;
        }
    }

    cout << max << " " << start + 1 << " " << end + 1 << "\n";
  }
}
