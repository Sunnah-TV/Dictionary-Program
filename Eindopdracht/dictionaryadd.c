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
	
	if (!isInDictionary(word)){
		amountOfWords++;
		list = (struct relation *) realloc(list, sizeof(struct relation) * getAmountOfWords());

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
	}else{
		printf("Word not found\n");
	}
}

int makeSentence(char sentence[], char word[], char word2[]){
	strcat(sentence, " ");
	strcpy(sentence, word);
	strcpy(sentence, word2);
	return sentence;
}

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
	fseek(fp, 0, SEEK_END);
	fprintf(fp, text);
}