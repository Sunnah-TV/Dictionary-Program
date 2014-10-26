#ifndef _DICTIONARYSEARH_H_
#define _DICTIONARYSEARH_H_

#include "dictionary.h"

#define ARRAYLENGTH(x) (sizeof(x)/sizeof(x[0]));


int translateWord(char word[]);
int isInDictionary(char word[]);

#endif /*_DICTIONARYSEARH_H_*/