#include <stdio.h>

int power(int x, int y)
{
  if (y < 1)
  {
    return 1;
  }
  return power(x, y - 1) * x;
}

int power_opt(int x, int y) {
  if (y == 1) {
    return x;
  }
  if (y % 2 != 0) {
    return power_opt(x, y - 1) * x;
  }
  int half_ret = power_opt(x, y/2);
  return half_ret * half_ret;
}

int main(void) {
  printf("%i\n", power_opt(2, 4));
  printf("%i\n", power_opt(2, 5));
}