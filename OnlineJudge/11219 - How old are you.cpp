// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

void validate(int i){
    
    if(i > 130)
        cout << "Check birth date\n";
   else 
        cout << i <<"\n";
}
int main() {
    int T;
    cin >> T;
    for(int t = 1;t<=T;t++) {
        cout << "Case #"<<t<<": ";
        cin.ignore();
        int y,m,d,y2,m2,d2;
        cin >> d;
        cin.ignore();
        cin >> m;
        cin.ignore();
        cin >> y;
        cin >> d2;
        cin.ignore();
        cin >> m2;
        cin.ignore();
        cin >> y2;
        if(y < y2)
          cout << "Invalid birth date\n";
        else if(y == y2) {
            if(m < m2)
              cout << "Invalid birth date\n";
            else if(m == m2){
                if(d < d2){
                cout << "Invalid birth date\n";
                } else
              cout << 0 <<"\n";
            } else
              cout << 0 <<"\n";
        } else {
            if(m < m2) {
                validate(y-y2-1);
            } else if(m > m2) {
                validate(y-y2);
            } else {
                if (d < d2) {
                  validate(y-y2-1);
                } else if(d > d2) {
                  validate(y-y2);
                } else {
                  validate(y-y2);
                }
            }
        }
    }
}
