#include "dictionaryadd.h"

/*****************************************************************************
** Function name:       addWord
**
** Descriptions:        Adds a word with translation to the list. Reallocates
**					memory for this list and writes it to the currently open file.
**
** Parameters:         	char array path to which contains the file location
** Returned value:      None
**
*****************************************************************************/
#ifdef USE_POINTER
void addword(int *word, int *translation){
	struct relation temp;
	*temp.word = *word;
	*temp.translation = *translation;

	writeFile(temp.word);
	writeFile("\t");
	writeFile(temp.translation);
	printf("added word %s with translation %s.\n", temp.word, temp.translation);
}
#else
void addword(char word[], char translation[]){
	struct relation temp;
	strcpy(temp.word, word);
	strcpy(temp.translation, translation);

	writeFile(temp.word);
	writeFile(" ");
	writeFile(temp.translation);
	writeFile("\n");
	printf("added word %s with translation %s.\n", temp.word, temp.translation);
}
#endif

/*****************************************************************************
** Function name:       writeFile
**
** Descriptions:        Checcks whether file is open and writes to the file
**
** Parameters:         	char text contains the text that should written to the 
**						currently opened file
** Returned value:      None
**
*****************************************************************************/

void writeFile(char text[]){
	fprintf(fp, text);
}