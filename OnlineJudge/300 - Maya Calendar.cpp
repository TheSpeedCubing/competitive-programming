#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  cout << T<<"\n";
  while(T--){
  	int d, y;
  	string m;
    cin >> d;
    cin.ignore();
    cin >> m;
    cin >> y;
    
    string n[] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax","koyab", "cumhu","uayet"};
    string n2[] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", 
                   "eb","ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    int i = 0;
    while(1){
      if(n[i] == m)
        break;
      i++;
    }
    
    int result = d+i*20+y*365;
    int yearD = result % 260;
    
    cout <<  yearD % 13 + 1 <<" "<<n2[yearD % 20]<<" "<<result/260<<"\n";
  }
}
