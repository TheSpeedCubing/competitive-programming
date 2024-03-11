#include <bits/stdc++.h>

using namespace std;

int arr[1024], n, d;

bool isOutOfRange(int i, int j) {
    return abs(arr[i] - arr[j]) > (j - i) * d;
}

int main() {
    while (cin >> n >> d) {

        fill(arr, arr + 1024, 0);

        int i = 0, chance = 2;

        while (i < n) {
            cin >> arr[i++];
        }

        i = 0;
        while (i < n - 1) {
            if (isOutOfRange(i, i + 1)) {
                chance--;
                if (i < n - 2) {
                    if (isOutOfRange(i, i + 2)) {
                    	 int k = i ? 1 : 0;
                       chance -= isOutOfRange(i + 1 - 2 * k, i + 2 - k);
                    } else i++;
                }
            }
            i++;
        }

        cout << (chance > 0 ? "Yes\n" : "No\n");
    }
}