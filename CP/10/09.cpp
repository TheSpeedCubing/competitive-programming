#include <iostream>
using namespace std;

int main()
{
      int a , b;
      while(cin >> a >> b) {
          int copy = a;
            int t[a], m[b], i = 0,j = 0;
            for(;j<a;j++){
                cin >> t[j];
            }
            for(;i<b;i++){
                cin >> m[i];
              for(j = 0;j<a;j++) {
                  if(t[j] != -1 && m[i] != 0 && t[j] % m[i] == 0) {
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