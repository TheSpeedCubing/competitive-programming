#include <iostream>
using namespace std;

int main()
{
      int a , b;
      while(cin >> a >> b) {
          int copy = a, t[a], m[b], i = 0,j = 0;
            for(;j<a;j++) {
                cin >> t[j];
            }
            for(;i<b;i++){
                cin >> m[i];
              for(j = 0;j<a;j++) {
                  if(t[j] != -1 && m[i] && !(t[j] % m[i])) {
                      cout << t[j] <<(copy == 1 ?"\n": " ");
                      copy--;
                      t[j] = -1;
                  }
              }
            }
            for(j = 0;j < a;j++){
              if(t[j] != -1) {
                 cout << t[j] << (copy == 1 ?"\n": " ");
                 copy--;
            }
            }
      }
}
