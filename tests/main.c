#include "megabool.h"
#include <stdio.h>

int main(void) {
  // megabool flag = schrodinger;
  // printf("flag = %d\n", flag);
  // printf("real bool value: %s\n", getMegaboolValue(flag));
  testProgram = true;
  for (int i = false; i < megaBoolCount; i++) {
    if (i <= 9) {
      printf("Megabool %d  -> %s\n", i, getMegaboolValue((megabool)i));
    } else {
      printf("Megabool %d -> %s\n", i, getMegaboolValue((megabool)i));
    }
  }
  return 0;
}
