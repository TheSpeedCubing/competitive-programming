#include <stdio.h>

int main() {
  while (1) {

    int arr[4];
    int count[7] = {};
    int maxcount = 0;
    int in ;
    for (int i = 0; i < 4; i++) {
      scanf("%1d", & in);
      if (in == 0) {
        return 0;
      }
      count[in]++;
      arr[i] = in;
      maxcount = maxcount < count[in] ? count[in] : maxcount;
    }

    if (maxcount == 3 || maxcount == 1) {
      printf("-\n");
    } else if (maxcount == 2) {
      bool hasunique = false;
      for (int i : count) {
        hasunique = hasunique || (i == 1);
      }

      int result = 0;
        for (int i = 1; i <= 6; i++) {
          if(hasunique) {
            if (count[i] == 1) {
              result += i;
            }
          } else {
            if (count[i] == 2) {
              result = i*2 > result ? i*2 : result;
            }
        	}
        }
      if (result == 12) {
        printf("SiPaLa\n");
      } else if (result == 3) {
        printf("BG\n");
      } else {
        printf("%d\n", result);
      }
    } else {
      printf("SiPaLa\n");
    }
  }
}
