#ifndef _DICTIONARYADD_H_
#define _DICTIONARYADD_H_

#include "dictionary.h"

void addWord(char word[], char translation[]);
void deleteWord(char word[]);
int makeSentence(char[], char[], char[]);
void writeFile(char text[]);

#endif /*_DICTIONARYADD_H_*/