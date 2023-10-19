#include <stdio.h>

int rowS, columnS,row,column,i,flag,t;
int main() {
    while(scanf("%d%d", &rowS, &columnS)!=EOF){
        if (flag)
            printf("\n");
        else flag = 1;
        char s[rowS];
        s[rowS] = NULL;
        for (i = 0;i<columnS;) {
            row = i / rowS;
		        column = i % rowS;
		        t = rowS - column - 1;
            s[row % 2 ? t : column] = 97 + i % 26;
            if (!((++i) % rowS))
			          printf("%s\n",s);
		    } 
        
        if (columnS % rowS) {
            if(row % 2) 
                while(t--)
                    s[t] = 32;
            else 
			          s[column+1] = NULL;
            printf("%s\n", s);
        }
    }
}