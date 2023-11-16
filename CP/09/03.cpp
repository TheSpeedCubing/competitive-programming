#include <iostream>

using namespace std;

int main()
{
	int dd,mm,yy;
	
	while(cin >> dd) {
		cin.ignore();
		cin >> mm;
		cin.ignore();
		cin >> yy;
		int data[] = {0,31,28+((!(yy % 4) && yy % 100) || !(yy % 400))
		,31,30,31,30,31,31,30,31,30,31};
		
		if(dd > data[mm] || dd < 1)
		  cout <<"Invalid date\n";
		else {
			while(mm--) {
			 	  dd+=data[mm];
			}
			 cout << dd <<"\n";
		}
	}
}
