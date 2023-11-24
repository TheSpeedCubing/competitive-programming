#include <iostream>
using namespace std;
int main()
{
	int d , m , y;
	while(cin >> d){
		cin.ignore();
		cin >> m;
		cin.ignore();
		cin >> y;
		int data [] = {0,31,28,31,30,31,30,31,31,30,31,30,31,30};
		if(((!(y%4) && (y%100)) || (!(y % 400))))
		  data[2]++;
		if(d < 1 || d > data[m] || m > 12) {
		  cout <<"Invalid date!\n";
		  continue;
  }		
   while(m--) {
			d += data[m];
		}
		cout << d <<"\n";
	}
}
