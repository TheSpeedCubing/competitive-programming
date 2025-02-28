#include <bits/stdc++.h>
using namespace std;
enum CURSOR{HOME, END};
char line[100001];
char mkText[200010];
char *head, *tail;
CURSOR  cursor;
void insertText(char *text)
{
    int len = strlen(text);
    if(cursor==END){
        strcpy(tail, text);
        tail += len;
    }
    else{
        strncpy(head-len, text, len);
        head -= len;
    }
}
int main() {
    while(cin.getline(line, 100001)) {
        head = tail = mkText + 100005;
        *tail='\0';
        cursor = END;
        char *p=line, *q;
        while(q=strpbrk(p, "<>")){
            bool tohome=*q=='<';
            *q=0;
            insertText(p);
            cursor = tohome ? HOME : END;
            p = q+1;
        }
        insertText(p);
        p=head;
        while(*p) {
            if(*p==' ') *p='_';
            p++;
        }
        cout << head << endl;
    }
    return 0;
}
