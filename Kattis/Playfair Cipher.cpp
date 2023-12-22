#include <bits/stdc++.h>

using namespace std;

struct Pos {
     int r;
     int c;
};

Pos position[128] = {};
char n[5][5];

void read(int r,int c){
     if(r == 5)
       r = 0;
     if(c == 5)
       c = 0;
     cout << n[r][c];
}
void encrypt(char c1,char c2) {
    if(c1 == c2)
      c2 = 'X';
    Pos pos1 = position[c1];
    Pos pos2 = position[c2];
    if(pos1.r == pos2.r) {
         read(pos1.r,pos1.c+1);
         read(pos2.r,pos2.c+1);
    } else if(pos1.c == pos2.c) {
         read(pos1.r+1,pos1.c);
         read(pos2.r+1,pos2.c);
    } else {
         read(pos1.r,pos2.c);
         read(pos2.r,pos1.c);
    }
}

int main() {
     string s1,s2;
     getline(cin,s1);
     getline(cin,s2);
     
     //5x5
     bool placed[128] = {false};
     placed['Q'] = true;
     int i = 0;
     for(char c : s1) {
           c = toupper(c);
           if(!placed[c] && isalpha(c)) {
                placed[c] = true;
                position[c] = {i/5,i%5};
                n[i/5][i%5] = c;
              i++;
           }
     }
     char c = 'A';
     while(i<25) {
          while(c <= 'Z') {
            if(!placed[c]) {
                placed[c] = true;
                position[c] = {i/5,i%5};
                n[i/5][i%5] = c;
                break;
            }
            c++;
          }
          i++;
     }
     
     //read string and encrypt
     char l = '#';
     for(char c : s2) {
          c = toupper(c);
          if(isalpha(c)) {
               if(l == '#')
              l = c;
            else {
                 if(l == c)
                   encrypt(l, 'X');
              else {
                   encrypt(l, c);
                   l = '#';
              }
            }
          }
     }
     if(l != '#') {
          encrypt(l, 'X');
     }
}
