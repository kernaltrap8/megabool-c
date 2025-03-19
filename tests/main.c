#include "megabool.h"
#include <stdio.h>

int main(void) {
  megabool flag = maybefalse;
  printf("flag = %d\n", flag);
  printf("real bool value: %s\n", getMegaboolValue(flag));
  return 0;
}
