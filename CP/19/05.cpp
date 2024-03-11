#include <bits/stdc++.h>

using namespace std;

double sign(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y) {
    return (p1x - p3x) * (p2y - p3y) - (p2x - p3x) * (p1y - p3y);
}

struct Figure {
  double d[6];
  char c;
  int dots[3] = {};
  Figure(char c): c(c) {
    int i = (c == 'r') ? 4 : (c == 'c' ? 3 : 6);
    for (int j = 0; j < i; j++)
      cin >> d[j];
  }
  
  bool validate(double x,double y,char c2) {
    bool inTheArea = false;    
    if (c == 'c')
        inTheArea = inTheArea || (d[2] * d[2] > pow(d[1] - y, 2) + pow(d[0] - x, 2));
    if (c == 'r')
        inTheArea = inTheArea || (x > min(d[0], d[2]) && x < max(d[0], d[2]) && y > min(d[1], d[3]) && y < max(d[1], d[3]));
    if (c == 't') {
        double d1 = sign(x, y, d[0], d[1], d[2], d[3]),
               d2 = sign(x, y, d[2], d[3], d[4], d[5]),
               d3 = sign(x, y, d[4], d[5], d[0], d[1]);
        inTheArea = inTheArea || !(((d1 < 0) || (d2 < 0) || (d3 < 0)) && ((d1 > 0) || (d2 > 0) || (d3 > 0)));
    }
    if(inTheArea)
      	 dots[c2 == 'R' ? 0 : (c2 == 'G' ? 1 : 2)]++;
    return inTheArea;
  }
};

vector < Figure * > f;

struct Pos {
  double x, y;
  char c;
  set < int > in;
  Pos(char c): c(c) {
    cin >> x >> y;
    int j = 0;
    for (Figure * ff: f) {
      if(ff->validate(x,y,c))
          in.insert(j);
      j++;
    }
  };
};

vector < Pos * > p;

int main() {
  char c , FLAG = 0;
  while(1) {
  	p.clear();
  	f.clear();
  while (1) {
  	if(!(cin >> c))
  	  exit(0);
    if(c == '*') 
      break;
    f.push_back(new Figure(c));
  }
  if(FLAG++)
  	 cout <<"^^^\n";
  while (cin >> c && c != 'X') {
    p.push_back(new Pos(c));
  }
  int i = 1;
  string name[3] = {" red"," green"," blue"};
  for (Figure * ff: f) {
    cout << "Figure "<<i<<":\n";
    int j = 0, k, f = 1;
    while(j<3) {
    	k = ff -> dots[j];
    	if(k) {
    		 f = 0;
    		 cout << "contains "<<k<< name[j] << (k==1?" dot\n":" dots\n");
    	}
    	j++;
    }
    if(f)
      cout <<"does not contain any color dot\n";
    i++;
  }
  cout <<"\n";
  i = 1;
  for (Pos* pp : p) {
  	cout << "Dot "<<i<<":\n";
  	 if(pp->in.size()) {
  	 	  for(int j : pp->in)
  	 	     cout << "contained in Figure "<<(j+1)<<"\n";
  	 } else cout << "not contained in any figure\n";
  	 i++;
  }}
}