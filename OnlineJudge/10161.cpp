#include <stdio.h>

int main(){
    int in;
    while(1){
        scanf("%d",&in);
        if(in == 0)
           break;
        int column = 1,s = 1;
        while(in - s > 0) {
            in -= s;
            s += 2;
            column++;
        }
        int f1 = in <= column, f2 = column % 2;
        int a = f1 ? column : s-in+1 , b = f1 ? in : column;
        printf("%d %d\n", f2 ? a : b, f2 ? b : a);
    }    
}