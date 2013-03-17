#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
  int x, y;
  int max = 1;
  while (scanf("%d %d", &x, &y) == 2)
  {
    printf("%d %d ", x, y);
    max = 1;
    if (x > y) {
      x = x ^ y;
      y = y ^ x;
      x = y ^ x;
    }
    for (int i = x; i <= y; i ++) {
      int j = i;
      int k = 1;
      
      while (j != 1) {
        if (j % 2 == 0)
          j >>= 1;
        else
          j = j * 3 + 1;
        k ++;
      }
      if (k > max)
        max = k;
    }
    printf("%d\n", max);
  }
  return 0;
}
