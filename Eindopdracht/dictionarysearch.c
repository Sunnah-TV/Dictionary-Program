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

int translateWord(struct relation **list, char word[]){
	int i = 0, exit = 0;
	int *ptr = 0;
	for (i = 0; i < getAmountOfWords() && !exit; i++){
		int j = 0;
		for (j = 0; j < sizeof(word) / sizeof(char); j++){
			if (word[j] != (*list)[i].word[j]){
				break;
			}else if (j == (sizeof(word) / sizeof(char))-1){
				ptr = (int *)((*list)[i].translation);
				exit = 1;
				break;
			}
		}
	}
	return ptr;
}

/*****************************************************************************
** Function name:       translateWords
**
** Descriptions:        translates the words seperated by ' '.
**
** Parameters:         	char array wich contains the words you are looking for
** Returned value:      None
**
*****************************************************************************/

void translateWords(struct relation **list, char input[], int length){
	int i = 0, counter = 0, size = 1;
	char buffer[30];
	struct relation *temp = NULL;
	temp = (struct relation *) malloc(sizeof(struct relation) * size);
	for (i = 0; i < length+1; i++){
		if (input[i] == ' '){
			buffer[i-counter] = '\0';
			temp = realloc(temp, (sizeof(struct relation) * size));
			strcpy_s(temp[size - 1].word, (i - counter) + 1, buffer);
			counter = i + 1;
			size++;
			memset(buffer, '\0', i);
		}else if (input[i] == '\0'){
			buffer[i - counter] = input[i];
			temp = realloc(temp, (sizeof(struct relation) * size));
			strcpy_s(temp[size - 1].word, (i - counter) + 1, buffer);
			break;
		}else{
			buffer[i-counter] = input[i];
		}
	}
	for (i = 0; i < size; i++){
		int tempInt = translateWord(*&list, temp[i].word);
		if (tempInt != NULL){
			strcpy_s(temp[i].translation, 30, tempInt);
		}else{
			strcpy_s(temp[i].translation, 30, "no translation found");
		}
		printf("%s --> %s\n", temp[i].word, temp[i].translation);
	}
	free(temp);
}

/*****************************************************************************
** Function name:       isInDictionary
**
** Descriptions:        checks whether a word is in the dictionary. Use this
**						functie when adding a word 
**
** Parameters:         	char array wich contains the word you are looking for
** Returned value:      returns position of word in list. 
**						0 when not found
*****************************************************************************/

int isInDictionary(struct relation **list, char word[]){
	int i = 0, j = 0, exit = 0;
	for (i = 0; i < getAmountOfWords() && !exit; i++){
		for (j = 0; j < sizeof(word) / sizeof(char); j++){
			if (word[j] == (*list)[i].word[j]){
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
** Function name:       isTranslationInDictionary
**
** Descriptions:        checks whether a translation is in the dictionary. Use this
**						functie when adding a word
**
** Parameters:         	char array wich contains the word you are looking for
** Returned value:      returns position of word in list.
**						0 when not found
*****************************************************************************/

int isTranslationInDictionary(struct relation **list, char translation[]){
	int i = 0, j = 0, exit = 0;
	for (i = 0; i < getAmountOfWords() && !exit; i++){
		for (j = 0; j < sizeof(translation) / sizeof(char); j++){
			if (translation[j] == (*list)[i].translation[j]){
				if (j == (sizeof(translation) / sizeof(char)-1)){
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