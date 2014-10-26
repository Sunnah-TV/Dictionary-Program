#ifndef _DICTIONARYADD_H_
#define _DICTIONARYADD_H_

#include "dictionary.h"

void addWord(char word[], char translation[]);
void deleteWord(char word[]);
void changeTranslation(char word[], char translation[]);
void changeWord(char word[], char newWord[]);
int makeSentence(char[], char[], char[]);
void writeFile(char text[]);
int checkWords(char word[], char translation[]);
void rewriteFile();

#endif /*_DICTIONARYADD_H_*/