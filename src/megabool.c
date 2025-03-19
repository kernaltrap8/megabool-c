#include "megabool.h"
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

__attribute__((visibility("default"))) megabool
getSchrodingerValue(void) {
  srand((unsigned int)time(NULL));
  return rand() % 2;
}

__attribute__((visibility("default"))) megabool
getTrueOnWeekendsValue(void) {
  time_t currentTime;
  struct tm *localTime;

  currentTime = time(NULL);

  localTime = localtime(&currentTime);

  int dayOfWeek = localTime->tm_wday;

  if (dayOfWeek == 0) {
    puts("its sunday");
    return true;
  } else if (dayOfWeek == 6) {
    puts("its saturday");
    return true;
  }
  puts("its probably a different day of the week, come back later.");
  return false;
}

__attribute__((visibility("default"))) megabool
checkForCops(void) {
  FILE *fp;
  char result[10];

  fp = popen("getenforce", "r");
  if (fp == NULL) {
      perror("popen");
      return 1;
  }

  if (fgets(result, sizeof(result), fp) != NULL) {
      result[strcspn(result, "\n")] = '\0';

      if (strcmp(result, "Enforcing") == 0) {
          return true;
      } else if (strcmp(result, "Permissive") == 0) {
          return true;
      } else if (strcmp(result, "Disabled") == 0) {
          return false;
      }
  } else {
      return false;
  }

  fclose(fp);
  return false;
}

__attribute__((visibility("default"))) void
checkForUndefinedBehavior(void) {
  fflush(stdout);
  raise(SIGSEGV);
}

__attribute__((visibility("default"))) megabool
_thinkingAboutIt(void) {
  srand((unsigned int)time(NULL));
  int waitTime = rand() % 91 + 10;
  puts("Hold on, let me think...");
  sleep(waitTime);
  return getSchrodingerValue();
}

__attribute__((visibility("default"))) megabool
megaBoolToBool(megabool Bool) {
  switch(Bool) {
    case false:
      return false;
    case true:
      return true;
    case schrodinger:
      return getSchrodingerValue();
    case sometimes:
      return false; // temporary
    case always:
      return true;
    case maybefalse:
      return false;
    case maybetrue:
      return true;
    case kindafalse:
      return true;
    case kindatrue:
      return false;
    case absolutelyfalse:
      return false;
    case absolutelytrue:
      return true;
    case withoutADoubtFalse:
      return false;
    case withoutADoubtTrue:
      return true;
    case quantumMaybe:
      return getSchrodingerValue();
    case notSureButProbablyFalse:
      return getSchrodingerValue();
    case notSureButProbablyTrue:
      return getSchrodingerValue();
    case trueOnWeekends:
      return getTrueOnWeekendsValue();
    case dependsWhoAsks:
      return false;
    case undefinedBehavior:
      checkForUndefinedBehavior();
      return false;
    case whatAreYouACop:
      return checkForCops();
    case thinkingAboutIt:
      return _thinkingAboutIt();
    case flase:
      return false;
    case treu:
      return true;
    case eslaf:
      return true;
    case eurt:
      return false;
    default:
      return false;
  }
}

__attribute__((visibility("default"))) const char *
getMegaboolValue(megabool Bool) {
  const char *value = getMegaboolString(Bool);
  if (Bool == undefinedBehavior && testProgram == megaBoolToBool(trueOnWeekends)) {
    checkForUndefinedBehavior();
  }
  return value;
}
