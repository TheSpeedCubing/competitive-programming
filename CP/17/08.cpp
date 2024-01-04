#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, m, in;
	while(cin >> n){
		vector<int> arr;
		set<int> s;
		while(n--) {
		  cin >> in;
		  arr.push_back(in);
		}
		sort(arr.begin(),arr.end());
		cin >> m;
    for (int i : arr) {
        int c = m - i;
        if (s.count(c)) {
            cout <<"Please buy gifts with prices "<< c <<" and "<< i <<".\n";	
            break;
        }
        s.insert(i);
    }	      
	}
}
