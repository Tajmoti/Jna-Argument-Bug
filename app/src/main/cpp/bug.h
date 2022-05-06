#ifndef JNAARGUMENTBUG_LIBRARY_H
#define JNAARGUMENTBUG_LIBRARY_H

#include <stdbool.h>

typedef unsigned short UINT16;

const UINT16 CONSTANT = 0x8810u;

bool hello(UINT16 argument);

bool hello_optimizations_disabled(UINT16 argument);

#endif //JNAARGUMENTBUG_LIBRARY_H
