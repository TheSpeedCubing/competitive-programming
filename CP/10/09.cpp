#include <iostream>
using namespace std;

int main()
{
      int a , b;
      while(cin >> a >> b) {
          int copy = a;
            int t[a];
            for(int i = 0;i<a;i++){
                cin >> t[i];
            }

            int m[b];
            for(int i = 0;i<b;i++){
                cin >> m[i];
              for(int j = 0;j<a;j++) {
                  if(t[j] != -1 && m[i] != 0 && t[j] % m[i] == 0) {
                      cout << t[j] <<(copy == 1 ?"\n": " ");
                      copy--;
                      t[j] = -1;
                  }
              }
            }
            for(int j = 0;j < a;j++){
              if(t[j] != -1) {
                 cout << t[j] << (copy == 1 ?"\n": " ");
                 copy--;
            }
            }
      }
}