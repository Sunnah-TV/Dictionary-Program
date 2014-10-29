#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include "dictionaryadd.h"
#include "dictionarysearch.h"
#include "util.h"

#define RW_OK	6		/* Test dor read and write permission*/
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
#define F_OK    0       /* Test for existence.  */

#define MAX_CHARS_ON_LINE 62

#define FALSE 0
#define TRUE 1

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

unsigned int amountOfWords;

void openFile(FILE **, char[]);
void closeFile(FILE **);
void loadFile(FILE **, struct relation **list);
int getLinesInFile(FILE **);
int getAmountOfWords();
void printHelp();
void printAll(struct relation **list);
void closeDictionary(FILE **, struct relation **list);

#endif /*_DICTIONARY_H_*/