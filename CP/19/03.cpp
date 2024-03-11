#include <bits/stdc++.h>
using namespace std;

typedef struct{
    double real;
    double imag;
} COMPLEX;

int main() {
	double a, b, c, d;
	char o, first = 0;
	string s;
	while(1) {
		if(first) {
			 cin >> o;
			 if(o == '^') {
		     getline(cin,s);
			   first = 0;
			   printf("%.5f%s%.5fi\n",a,(b >= 0 ? "+":""),b);
			   continue;
			 }
		}
		if(!(cin >> c >> d))
		  exit(0);
		if (first++) {
			 double temp = a , mom = c * c + d * d;
			 if(o == '+') {
			      a+=c;
			      b+=d;
			 }
			 if(o == '-') {
			      a-=c;
			      b-=d;
			 }
			 if(o == '*') {
			      a = temp * c - b * d;
			      b = b * c + temp * d;
			 }
			 if(o == '/') {
			      a = (temp * c + b * d) / mom;
			      b = (b * c - temp * d) / mom;
			 }
		} else {
			 a = c;
			 b = d;
		}
		getline(cin,s);
	}
}

