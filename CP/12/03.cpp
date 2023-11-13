
#include <iostream>
using namespace std;



int getDayCntbyYYMM(int y,int m) {
	int dt[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
	if ((!(y % 4) && y % 100) || !(y % 400)) {
		dt[2]++;
	}
	return dt[m];
}

int main() {
    int y, m, d, s;
    while (cin >> y) {
        cin.ignore();
        cin >> m;
        cin.ignore();
        cin >> d;
        cin >> s;

        if (d > getDayCntbyYYMM(y,m)) {
            cout << "Invalid date!\n";
            continue;
        }
        int flag = s > 0;
        s = flag ? s : -s;
        while(s--){
        	if(flag) {
                d++;
                if (d > getDayCntbyYYMM(y,m)) {
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
                    d = getDayCntbyYYMM(y,m);
                }
        	}
        }
        printf("%04d-%02d-%02d\n",y,m,d);
    }
}
