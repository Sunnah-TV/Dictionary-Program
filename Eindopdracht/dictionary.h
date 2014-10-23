#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <stdio.h>
#include <io.h>
#include "dictionaryadd.h"
#include "dictionarysearch.h"
#include "util.h"

#define RW_OK	6		/* Test dor read and write permission*/
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
#define F_OK    0       /* Test for existence.  */

#define MAX_CHARS_ON_LINE 62

#ifdef USE_POINTER
struct relation{
	char *word;
	char *translation;
};
#else
struct relation{
	char word[30];
	char translation[30];
};
#endif

FILE *fp;
struct relation *list;
unsigned int amountOfWords;

void openFile(char path[]);
void closeFile();
void printHelp();
void loadFile();
int getLinesInFile();
int getAmountOfWords();

#endif /*_DICTIONARY_H_*/