#include <iostream>
using namespace std;
 
int main() {
	  int T;
    cin >> T;
    while (T--) {
    	  int n[1024];
        int N;
        cin >> N;
        int s = 0;
        for (int i = 0; i < N; i++) {
            cin >> n[i];
            for (int j = 0; j < i; j++) {
                if (n[j] <= n[i]) {
                    s++;
                }
            }
        }
        cout << s << "\n";
    }
}
