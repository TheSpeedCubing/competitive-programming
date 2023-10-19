#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int k,w;
        scanf("%d%d",&k,&w);
        
        int result = k;
        
        char n[k] , s[k];
        scanf("%s",n);
        
        while(--w){
            scanf("%s",s);
            int base = 0;
            for(; base < k; base++){
                if(n[base] == s[0]) {
                    //search
                    int flag = 1;
                    for(int i = base;i<k;i++){
                        if (n[i] != s[i-base])
                            flag = 0;
                    }
                    //search end
                    if(flag)
                      break;
                }
            }
            result += base;
            for(int i = 0;i<k;i++){
                n[i] = s[i];
            }
        }
            printf("%d\n",result);
    }
}
