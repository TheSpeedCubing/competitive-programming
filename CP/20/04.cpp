#include <bits/stdc++.h>

using namespace std;

struct STUDENT_REC {
  unsigned short age: 4; // 4 bits; 3-18
  unsigned short grade: 4; // 4 bits; 1-12
  unsigned short sex: 1; // 1 bit;  0(F), 1(M)
  unsigned short gpa: 6; // 6 bits; 0.0-4.0
};

int main() {
  string s1, s2;
  char escape;
  int N, in;
  cin >> s1 >> s2;

  FILE* f;
  STUDENT_REC s;
  
  if (s1 == "save") {
    cin >> N;

    unsigned short a, b, c, d;

    f = fopen(s2.c_str(), "wb");
    fwrite( & N, 4, 1, f);

    while (N--) {
      cin >> a >> b >> s1 >> c >> escape >> d;
      s = {
        a - 3,
        b - 1,
        s1 == "M",
        c * 10 + d
      };
      fwrite( & s, sizeof(s), 1, f);
    }
    fclose(f);

    f = fopen(s2.c_str(), "rb");

    int i = 0;
    while ((in = fgetc(f)) != EOF) {
      printf("%s%02X", (i % 16 ? " " : (i ? "\n" : "")), in);
      i++;
    }
    cout << "\n";
  } else {
    f = fopen(s2.c_str(), "rb");
    fread( & N, 4, 1, f);
    while (N--) {
      fread(&s, sizeof(s), 1, f);
      printf("%2d %2d %c %d.%d\n", s.age + 3, s.grade + 1, (s.sex ? 'M' : 'F'), s.gpa / 10, s.gpa % 10);
    }
  }
}