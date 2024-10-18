#include <bits/stdc++.h>

using namespace std;

struct Point {
   double x, y, z;
};

double sq(double x) {
	return x * x;
}

double distance(Point p1, Point p2) {
	return sqrt(sq(p1.x - p2.x) + sq(p1.y - p2.y) + sq(p1.z - p2.z));
}

int main() {
  string s;
  double x1,y1,z1,x2,y2,z2;
  int n;
  double x,y,z,r;
  
  while(cin >> s) {
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
	Point l1 = {x1,y1,z1}; //low
	Point l2 = {x2,y2,z2}; //high
	double len = distance(l1,l2);
    cin >> n;
	double sum = 0;
	while(n--) {
	  cin >> x >> y >> z >> r;
	  
	  //dotx = x1 + vx * t 
	  //doty = y1 + vy * t
	  //dotz = z1 + vz * t
	  Point vector = {x2-x1,y2-y1,z2-z1};
	  
	  //(dotx - x)^2 + (doty - y)^2 + (dotz - z)^2 = r ^ 2
	  //(x1 + vx * t - x)^2 + (y1 + vy * t - y)^2 + (z1 + vz * t - z)^2 = r^2
	  //((x1 - x) + vx * t)^2 + (y1 - y + vy * t)^2 + (z1 - z + vz * t)^2 = r^2
	  //(x3 + vx * t)^2 + (y3 + vy * t)^2 + (z3 + vz * t)^2 = r ^ 2
	  int x3 = x1 - x, y3 = y1 - y, z3 = z1 - z;

	  //(vx^2 + vy^2 + vz^2) * t^2 + 2 * (vx * x3 + vy * y3 + vz * z3) * t + (x3^2 + y3^2 + z3^2 - r ^ 2) = 0
	  int a = sq(vector.x) + sq(vector.y) + sq(vector.z);
	  
	  int b = 2 * (vector.x * x3 + vector.y * y3 + vector.z * z3);
	  
	  int c = sq(x3) + sq(y3) + sq(z3) - sq(r);

	  //D
      int D = sq(b)-4*a*c;

      if(D < 0) {
          continue;
       }
	  
	  double t1 = (-b - sqrt(D))/2/a; //low
	  double t2 = (-b + sqrt(D))/2/a; //high
	  
	  //the vector multipleir of l1 and l2 is 0 and 1
      
	  if(t1 < 0 && t2 < 0) { //out of range
		continue;
	  }

	  if(t1 > 1 && t2 > 1) { //out of range
		continue;
	  }

	  if(t1 < 0 && t2 < 1) { // t1 < 0 < t2 < 1 -> move to t1=0 < t2 < 1
			t1 = 0;
	  } else if(t1 < 0 && 1 < t2) { // t1 < 0 < 1 < t1 -> move to t1=0 t2=1
			t1 = 0;
			t2 = 1;
	  } else if(t1 < 1 && 1 < t2) { // 0 < t1 < 1 < t2 -> 0 < t1 < t2=1
			t2 = 1; 
	  }
	  
	  Point dot1 = {x1 + vector.x * t1, y1 + vector.y * t1, z1 + vector.z * t1};
	  Point dot2 = {x1 + vector.x * t2, y1 + vector.y * t2, z1 + vector.z * t2};
	  
	  sum += distance(dot1, dot2);
	}
	cout << s <<"\n";
	printf("%.2f\n", sum / len * 100);
  }
}
