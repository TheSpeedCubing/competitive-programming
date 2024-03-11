#include <bits/stdc++.h>

using namespace std;

int main() {
	int a,b,c,m,n,k,t = 1;
	while(cin >> a >> b >> c >> m >> n >> k) {
		 vector<int> x;
		 x.push_back(a);
		 x.push_back(b);
		 x.push_back(c);
		 for(int i = 3;i<n;i++) {
		 	  x.push_back((x[i-1] + x[i-2] + x[i-3]) % m + 1);
		 }
    
    map<int,int> count;
    
    int r = k,
        left = 0,
        minLength = 2147483647;
    for (int right = 0; right < n; right++) {
        int i = x[right];

        r -= (i <= k && !count[i]);

        count[i]++;
        while (!r) {
            minLength = min(minLength, right - left + 1);
            if (x[left] <= k) {
                count[x[left]]--;
                r += (!count[x[left]]);
            }
            left++;
        }
    }
    cout << "Case "<<t++<<": "<< (minLength == 2147483647 ? "unavailable" : to_string(minLength)) << endl;
  
	}
}
