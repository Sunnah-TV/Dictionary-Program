#include "dictionaryadd.h"

/*****************************************************************************
** Function name:       addWord
**
** Descriptions:        Adds a word with translation to the list. Reallocates
**						memory for this list and writes it to the currently open file.
**
** Parameters:         	char array path to which contains the file location
** Returned value:      None
**
*****************************************************************************/
void addWord(FILE **fp, struct relation **list, char word[], char translation[]){
	char temp[65];
	
	if (checkWords(word, translation)){
		if (!isInDictionary(*&list, word)){
			//if (!isTranslationInDictionary(list, translation)){
				amountOfWords++;
				*list = realloc(*list, sizeof(struct relation) * getAmountOfWords());
				strcpy_s((*list)[getAmountOfWords() - 1].word, 30, word);
				strcpy_s((*list)[getAmountOfWords() - 1].translation, 30, translation);

				strcpy_s(temp, _countof(temp), word);
				strcat_s(temp, _countof(temp), " ");
				strcat_s(temp, _countof(temp), translation);
				strcat_s(temp, _countof(temp), " \n");
		
				writeFile(*&fp, temp);
				printf("added word %s with translation %s.\n", word, translation);
			
		}else{
			printf("Word is not added to list, list already contains this translation.\n");
		}
	}
	else{
		printf("You cannot use spaces in the words you want to add.\n");
	}
}

/*****************************************************************************
** Function name:       deleteWord
**
** Descriptions:        Deletes a word from the memory and saves it to the
**						text file.
**
** Parameters:         	char array with the word that should 
** Returned value:      None
**
*****************************************************************************/

void deleteWord(FILE **fp, struct relation **list, char word[]){
	int place = isInDictionary(*&list, word);
	if (place != NULL){
		int i = 0;
		for (i = place; i < (getAmountOfWords()); i++){
			strcpy_s((*list)[i].word, 30, (*list)[i + 1].word);
			strcpy_s((*list)[i].translation, 30, (*list)[i + 1].translation);
		}
		amountOfWords--;
		*list = (struct relation *) realloc(*list, (sizeof(struct relation)*amountOfWords));
		rewriteFile(*&fp, *&list);
	}else{
		printf("Word not found!\n");
	}
}

/*****************************************************************************
** Function name:       changeTranslation
**
** Descriptions:        Changes a translation of a word that is alreadt in	
**						the list.
**
** Parameters:         	char array with the word that should be changed
**						char array translation with the translation that should be changed
** Returned value:      None
**
*****************************************************************************/

void changeTranslation(FILE **fp, struct relation **list, char word[], char translation[]){
	int position = isInDictionary(*&list, word)+1;
	if (position){
		strcpy_s((*list)[position-1].translation, 30, translation);
		rewriteFile(*&fp, *&list);
	}else{
		printf("Word not found!\n");
	}
}

/*****************************************************************************
** Function name:       changeWord
**
** Descriptions:        changes word 
**
** Parameters:         	char array with the word that should be changed
**						char array translation with the translation that should be changed
** Returned value:      None
**
*****************************************************************************/

void changeWord(FILE **fp, struct relation **list, char word[], char newWord[]){
	int position = isInDictionary(*&list, word)+1;
	if (position>=0){
		strcpy_s((*list)[position-1].word, 30, newWord);
		rewriteFile(*&fp, *&list);
	}else{
		printf("Word not found!\n");
	}
}

/*****************************************************************************
** Function name:       makeSentence
**
** Descriptions:        adds char array to another char array words will be 
**						sepperated by a ' '
**
** Parameters:         	sentence char array which the other two words will be added
**						to this char array
**						word char array contains the first word that must be added
**						word2 char array contains the second word that must be added
**
** Returned value:      None
**
*****************************************************************************/

int makeSentence(char sentence[], char word[], char word2[]){
	strcat_s(sentence, 1, " ");
	strcat_s(sentence, 30, word);
	strcat_s(sentence, 1, " ");
	strcat_s(sentence, 30, word2);
	return sentence;
}

/*****************************************************************************
** Function name:       writeFile
**
** Descriptions:        Checks whether file is open and writes to the file
**
** Parameters:         	char text contains the text that should written to the 
**						currently opened file
** Returned value:      None
**
*****************************************************************************/

void writeFile(FILE **fp, char text[]){
	fseek(*fp, 0, SEEK_END);
	fprintf(*fp, text);
}

/*****************************************************************************
** Function name:       checkWords
**
** Descriptions:		Checks the chars in a char array
**
** Parameters:         	char word contains the text that should be checked
**						char translation contains the translation which will
**						be checked
** Returned value:      False when word contains a ' '
**						True otherwise
**
*****************************************************************************/

int checkWords(char word[], char translation[]){
	int i;
	for (i = 0; i < sizeof(word) / sizeof(char); i++){
		if (word[i] == ' ') return FALSE;
	}
	for (i = 0; i < sizeof(translation) / sizeof(char); i++){
		if (translation[i] == ' ') return FALSE;
	}
	return TRUE;
}

/*****************************************************************************
** Function name:       rewriteFile
**
** Descriptions:		Deletes old file and creates new file with all words
**						that are currently in the memory
**
** Parameters:         	None
** Returned value:      None
**
*****************************************************************************/

void rewriteFile(FILE **fp, struct relation **list){
	int i;
	fclose(*fp);
	remove("dictionary.txt");
	fopen_s(&fp, "dictionary.txt", "w");
	for (i = 0; i < amountOfWords; i++){
		char temp[62];
		strcpy_s(temp, _countof(temp), (*list)[i].word);
		strcat_s(temp, _countof(temp), " ");
		strcat_s(temp, _countof(temp), (*list)[i].translation);
		strcat_s(temp, _countof(temp), " \n");
		fprintf(*&fp, temp);
	}
}