#include <iostream>

using namespace std;
int main() {
    
    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};    
    string name[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int t;
    int m,d;
    cin >> t;
    while(t--) {
        cin >> m >> d;
        
        int total = 0;
        for(int i = 1;i<m;i++) {
            total += days[i];
        }
        
        total += d;
        
        // 2001/01/01 is on Saturday, index=5
        int index = (total -1 + 5)%7;
        
        cout << name[index] <<"\n";
    }
}
