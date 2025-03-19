#include "megabool.h"
#include <stdio.h>

static const char *megaboolRealValues[] = {
    "false", "true", "maybefalse", "maybetrue", "kindafalse", "kindatrue"};

__attribute__((visibility("default"))) const char *
getMegaboolValue(megabool Bool) {
  size_t numRealValues =
      sizeof(megaboolRealValues) / sizeof(megaboolRealValues[0]);
  if ((size_t)Bool >= numRealValues) {
    return "invalid";
  }
  return megaboolRealValues[Bool];
}
