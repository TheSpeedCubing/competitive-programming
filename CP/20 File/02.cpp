#include <iostream>

#include <cstdio>

#include <string>

using namespace std;

int main() {
  string type, file1, file2;
  int n;
  cin >> type >> file1 >> file2 >> n;

  unsigned arr[1024];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  bool encrypt = type == "e";
  FILE * f1 = fopen(file1.c_str(), encrypt? "r" : "rb");
  FILE * f2 = fopen(file2.c_str(), encrypt ? "wb" : "w");
  
  int in , i = 0;
  while ((in = fgetc(f1)) != EOF) {
    int result = (in ^ arr[i % n]);
    if (encrypt) {
      printf("%s%02X", (i % 16 ? " " : (i ? "\n" : "")), result);
      fputc(result, f2);
    } else {
      cout << (char) result;
    }
    i++;
  }
  
  if (encrypt) {
    cout << "\n";
  }
}