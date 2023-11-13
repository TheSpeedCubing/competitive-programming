#include <iostream>

using namespace std;


int daysInYYMM(int year, int month) {
	int dt[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
	dt[2] += ((!(year % 4) && year % 100) || !(year % 400));
  return dt[month];
}

int isDateValid(int year, int month, int day){
	return day <= daysInYYMM(year,month);
}

int dateSubstraction(int year1, int month1, int day1, int year2, int month2, int day2) {
    if (year1 > year2 || 
          (year1 == year2 && (month1 > month2 || 
            (month1 == month2 && day1 > day2)))) {
        swap(year1, year2);
        swap(month1, month2);
        swap(day1, day2);
    }

    int days = 0;

    while (day1 != day2 || year1 != year2 || month1 != month2) {
        day1++;

        if (day1 > daysInYYMM(year1, month1)) {
            month1++;

            if (month1 > 12) {
                year1++;
                month1 = 1;
            }

            day1 = 1;
        }

        days++;
    }

    return days+1;
}


int main()
{
	int y1,m1,d1,y2,m2,d2;
	 while(cin >> y1>>m1>>d1>>y2>>m2>>d2) {
	 	if(isDateValid(y1,-m1,-d1) && isDateValid(y2,-m2,-d2)){
	 		 cout << dateSubstraction(y1,-m1,-d1,y2,-m2,-d2) <<"\n";
	 	} else cout <<"Invalid date!\n";
	 }
    return 0;
}
