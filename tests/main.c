#include "megabool.h"
#include <stdio.h>

int main(void) {
  testProgram = megaBoolToBool(whatAreYouACop);
  for (int i = false; i < megaBoolCount; i++) {
    if (i <= 9) {
      printf("Megabool %d  -> %s\n", i, getMegaboolValue((megabool)i));
    } else {
      printf("Megabool %d -> %s\n", i, getMegaboolValue((megabool)i));
    }
  }
  return 0;
}
