#ifndef _DICTIONARYSEARH_H_
#define _DICTIONARYSEARH_H_

#include "dictionary.h"

#define ARRAYLENGTH(x) (sizeof(x)/sizeof(x[0]))


int translateWord(struct relation **list, char[]);
int isInDictionary(struct relation **list, char[]);
int isTranslationInDictionary(struct relation **list, char[]);
void translateWords(struct relation **list, char[], int);

#endif /*_DICTIONARYSEARH_H_*/