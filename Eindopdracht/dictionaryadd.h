#ifndef _DICTIONARYADD_H_
#define _DICTIONARYADD_H_

#include "dictionary.h"

void addWord(FILE **, struct relation **list, char[], char[]);
void deleteWord(FILE **, struct relation **list, char[]);
void changeTranslation(FILE **, struct relation **list, char[], char[]);
void changeWord(FILE **, struct relation **list, char[], char[]);
int makeSentence(char[], char[], char[]);
void writeFile(FILE **, char[]);
int checkWords(char[], char[]);
void rewriteFile(FILE **, struct relation **list);

#endif /*_DICTIONARYADD_H_*/