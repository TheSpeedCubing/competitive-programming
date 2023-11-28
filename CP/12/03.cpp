
#include <iostream>
using namespace std;

int y, m, d, s;

int getDayCntbyYYMM2() {
	int dt[] = {0,31,28+((!(y % 4) && y % 100) || !(y % 400)) ,31,30,31,30,31,31,30,31,30,31};
	return dt[m];
}

int main() {
    while (cin >> y) {
        cin.ignore();
        cin >> m;
        cin.ignore();
        cin >> d;
        cin >> s;

        if (d > getDayCntbyYYMM2()) {
            cout << "Invalid date!\n";
            continue;
        }
        int flag = s > 0;
        s = max(s,-s);
        while(s--){
        	if(flag) {
                d++;
                if (d > getDayCntbyYYMM2()) {
                    d = 1;
                    if (++m > 12) {
                       m = 1;
                       y++;
                    }
                }
        	} else {
                d--;
                if (d < 1) {
                    m--;
                    if (m < 1) {
                        m = 12;
                        y--;
                    }
                    d = getDayCntbyYYMM2();
                }
        	}
        }
        printf("%04d-%02d-%02d\n",y,m,d);
    }
}
