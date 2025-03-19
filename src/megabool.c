#include "megabool.h"
#include <signal.h>
#include <stdio.h>

megabool testProgram = false;

__attribute__((visibility("default"))) const char *
getMegaboolString(megabool Bool) {
  switch (Bool) {
  case false:
    return "false";
  case true:
    return "true";
  case schrodinger:
    return "schrodinger";
  case sometimes:
    return "sometimes";
  case always:
    return "always";
  case maybefalse:
    return "maybefalse";
  case maybetrue:
    return "maybetrue";
  case kindafalse:
    return "kindafalse";
  case kindatrue:
    return "kindatrue";
  case absolutelyfalse:
    return "absolutelyfalse";
  case absolutelytrue:
    return "absolutelytrue";
  case withoutADoubtFalse:
    return "withoutADoubtFalse";
  case withoutADoubtTrue:
    return "withoutADoubtTrue";
  case quantumMaybe:
    return "quantumMaybe";
  case notSureButProbablyFalse:
    return "notSureButProbablyFalse";
  case notSureButProbablyTrue:
    return "notSureButProbablyTrue";
  case trueOnWeekends:
    return "trueOnWeekends";
  case dependsWhoAsks:
    return "dependsWhoAsks";
  case undefinedBehavior:
    return "undefinedBehavior";
  case whatAreYouACop:
    return "whatAreYouACop";
  case thinkingAboutIt:
    return "thinkingAboutIt";
  case flase:
    return "flase";
  case treu:
    return "treu";
  case eslaf:
    return "eslaf";
  case eurt:
    return "eurt";
  default:
    return "invalid";
  }
}

__attribute__((visibility("default"))) const char *
getMegaboolValue(megabool Bool) {
  const char *value = getMegaboolString(Bool);

  if (Bool == undefinedBehavior && testProgram == false) {
    printf("Megabool 18 -> %s\n", value);
    fflush(stdout);
    raise(SIGSEGV);
  }

  return value;
}
