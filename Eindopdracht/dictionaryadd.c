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
void addWord(char word[], char translation[]){
	char temp[65];
	
	if (checkWords(word, translation)){
		if (!isInDictionary(word)){
			amountOfWords++;
			list = (struct relation *) realloc(list, sizeof(struct relation) * getAmountOfWords());
			strcpy(list[getAmountOfWords() - 1].word, word);
			strcpy(list[getAmountOfWords() - 1].translation, translation);

			strcpy(temp, word);
			strcat(temp, " ");
			strcat(temp, translation);
			strcat(temp, " \n");
		
			writeFile(temp);
			printf("added word %s with translation %s.\n", word, translation);
		}else{
			printf("Word is not added to list, list already contains this word.\n");
		}
	}
	else{
		printf("You cannot use spaces in the words you want to add.");
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

void deleteWord(char word[]){
	int place = isInDictionary(word);
	if (place != NULL){
		int i = 0;
		for (i = place; i < (getAmountOfWords()); i++){
			strcpy(list[i].word, list[i + 1].word);
			strcpy(list[i].translation, list[i + 1].translation);
		}
		amountOfWords--;
		list = (struct relation *) realloc(list, (sizeof(struct relation)*amountOfWords));
		rewriteFile();
	}else{
		printf("Word not found!\n");
	}
}

void changeTranslation(char word[], char translation[]){
	int position = isInDictionary(word);
	if (position){
		strcpy(list[position].translation, translation);
		rewriteFile();
	}else{
		printf("Word not found!\n");
	}
}

void changeWord(char word[], char newWord[]){
	int position = isInDictionary(word);
	if (position){
		strcpy(list[position].word, newWord);
		rewriteFile();
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
	strcat(sentence, " ");
	strcpy(sentence, word);
	strcpy(sentence, word2);
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

void writeFile(char text[]){
	fseek(fp, 0, SEEK_END);
	fprintf(fp, text);
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

void rewriteFile(){
	int i;
	fclose(fp);
	remove("dictionary.txt");
	fopen_s(&fp, "dictionary.txt", "w");
	for (i = 0; i < amountOfWords; i++){
		char temp[62];
		strcpy(temp, list[i].word);
		strcat(temp, " ");
		strcat(temp, list[i].translation);
		strcat(temp, " \n");
		fprintf(fp, temp);
	}
}