#include <bits/stdc++.h>

using namespace std;

int main() {
	int w, h;
	
	cin >> w >> h;
	
	char d;
	int x, y;
	string s;
	
	int vec[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	string dirs = "NESW";
	
	set<pair<int,int>> dead;
	
    while(cin >> x >> y >> d) {
		cin.ignore();
		int dir;
		if(d == 'N') {
			dir = 0;
		}
		if(d == 'E') {
			dir = 1;
		}
		if(d == 'S') {
			dir = 2;
		}
		if(d == 'W') {
			dir = 3;
		}
		
		getline(cin, s);
		
		bool lost = false;
		for(char c : s) {
			if(c == 'R') {
				dir++;
			}
			if(c == 'L') {
				dir--;
			}
			while(dir < 0) {
				dir += 4;
			}
			while(dir > 3) {
				dir -= 4;
			}
			
			if(c == 'F') {
				int nextx = x + vec[dir][0];
				int nexty = y + vec[dir][1];
				
				if(nextx > w || nextx < 0 || nexty > h || nexty < 0) {
					if(dead.count({x,y})) {
						continue;
					}
					dead.insert({x,y});
					lost = true;
					break;
				}
				
				x = nextx;
				y = nexty;
			}
		}
		
		cout << x <<" "<<y<<" "<<dirs[dir];
		if(lost) {
			cout << " LOST";
		}
		cout <<"\n";
   }
}
