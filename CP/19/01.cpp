#include <bits/stdc++.h>
using namespace std;


int main() {
	double p1,n;
	cin >> p1 >> n;
	string s;
	
	map<string,pair<double,double>> db;
	
	while(n--) {
		cin >> s >> db[s].first >> db[s].second;
	}
	while(cin >> s) {
	  double	a = db[s].first * p1,
		b = db[s].second * (1-p1);
		cout << (a > b ? "optimism\n" : (a<b?"pessimism\n":"no way to judge\n"));
		
	}
}
