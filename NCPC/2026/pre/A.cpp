#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
	cin >> N;

    while(N--) {
        int n, k;
        cin >> n >> k;
		
        vector<long long> a(n);
        
		for(int i = 0;i<n;i++) {
			cin >> a[i];
		}

        int up = 0, down = 0;
        int i = 1;
        while(i < n) {
            if(a[i] == a[i-1]) { 
				i++; 
				continue; 
			}
            bool inc = a[i] > a[i-1];
            int len = 2;
            int j = i + 1;
            while(j < n && (inc ? a[j] > a[j-1] : a[j] < a[j-1])) {
				len++;
				j++; 
			}
            if(len >= k) {
                if(inc) {
					up++;
                } else {
					down++;
				}
            }
            i = j;
        }
        cout << up << " " << down << "\n";
    }
}