#include <speedcubing>

int n[1024][1024];
int n2[1024][1024];

void multiply(int r,int c,bool op) {
     for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
              int sum = 0, k = c;
              while(k--)
               sum += op ? (n[i][k] * n2[k][j]) : (n2[i][k] * n[k][j]);
            cout << sum <<(j==r-1?"\n":" ");
        }
     }
}
        
int main()
{
  int x,y, flag = 0;
    while(cin >> x >> y && x){
        if(flag++)
          cout <<"\n";
        int in;
        for(int i = 0;i<x;i++){
          for(int j = 0;j<y;j++){
              cin >> in;
              n[i][j] = in;
              n2[j][i] = in;
          }
        }
        multiply(y,x,0);
        cout <<"\n";
        multiply(x,y,1);
    }
}