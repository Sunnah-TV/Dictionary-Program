#include "dictionarysearch.h"

/*****************************************************************************
** Function name:       translateWord
**
** Descriptions:        translates the word given as argument
**
** Parameters:         	char array wich contains the word you are looking for
** Returned value:      pointer to the translation
**
*****************************************************************************/

int translateWord(char word[]){
	int i = 0, exit = 0;
	int *ptr = 0;
	for (i = 0; i < getAmountOfWords() && !exit; i++){
		int j = 0;
		for (j = 0; j < sizeof(word) / sizeof(char); j++){
			if (word[j] != list[i].word[j]){
				break;
			}else{
				ptr = (int *)(list[i].translation);
				exit = 1;
				break;
			}
		}
	}
	return ptr;
}

/*****************************************************************************
** Function name:       isInDictionary
**
** Descriptions:        checks whether a word is in the dictionary. Use this
**						functie when adding a word 
**
** Parameters:         	char array wich contains the word you are looking for
** Returned value:      1 when the dictionay contains the word
**						0 when the distionary does not contain the word
*****************************************************************************/

int isInDictionary(char word[]){
	int i = 0, j = 0, exit = 0;
	for (i = 0; i < getAmountOfWords() && !exit; i++){
		for (j = 0; j < sizeof(word) / sizeof(char); j++){
			if (word[j] == list[i].word[j]){
				if (j == (sizeof(word) / sizeof(char)-1)){
					exit = i;
					break;
				}
			}else{
				break;
			}
		}
	}
	return exit;
}

/*****************************************************************************
** Function name:       printAll
**
** Descriptions:        prints all words that are currently in the mamory
**
** Parameters:         	None
** Returned value:      None
*****************************************************************************/

void printAll(){
	int i = 0;
	for (i = 0; i < getAmountOfWords(); i++){
		printf("%s\t%s\n", list[i].word, list[i].translation);
	}
}