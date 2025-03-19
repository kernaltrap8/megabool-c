#ifndef MEGABOOL_H
#define MEGABOOL_H

typedef enum {
  false,
  true,
  schrodinger,
  sometimes,
  always,
  maybefalse,
  maybetrue,
  kindafalse,
  kindatrue,
  absolutelyfalse,
  absolutelytrue,
  withoutADoubtFalse,
  withoutADoubtTrue,
  quantumMaybe,
  notSureButProbablyFalse,
  notSureButProbablyTrue,
  trueOnWeekends,
  dependsWhoAsks,
  undefinedBehavior,
  whatAreYouACop,
  thinkingAboutIt,
  flase,
  treu,
  eslaf,
  eurt,
  megaBoolCount
} megabool;

#ifdef _MSC_VER
#define compilerLies true
#endif

#ifdef __GNUC__
#define compilerLies quantumMaybe
#endif

#ifdef __clang__
#define compilerLies notSureProbablyFalse
#endif

extern megabool testProgram;

__attribute__((visibility("default"))) megabool megaBoolToBool(megabool Bool);
__attribute__((visibility("default"))) const char *
getMegaboolValue(megabool Bool);
#endif // MEGABOOL_H
