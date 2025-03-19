#ifndef MEGABOOL_H
#define MEGABOOL_H

typedef enum {
  false,
  true,
  maybefalse,
  maybetrue,
  kindafalse,
  kindatrue
} megabool;

const char *getMegaboolValue(megabool Bool);

#endif // MEGABOOL_H
