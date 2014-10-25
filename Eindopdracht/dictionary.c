#include "dictionary.h"

/*****************************************************************************
** Function name:       openFile
**
** Descriptions:        Opens file which is given in as the path
**
** Parameters:         	char array path to which contains the file location
** Returned value:      None
**
*****************************************************************************/

void openFile(char path[]){
	errno_t err;
	if (_access(path, F_OK)!=-1){
		err = fopen_s(&fp, path, "r+");
		if (err == 0) printf("Opened File %s\n", path);
		else printf("Cannot open File %s\n", path);
	}else{
		printf("File does not exist, created file %s\n", path);
		err = fopen_s(&fp, path, "w");
	}
}

/*****************************************************************************
** Function name:       closeFile
**
** Descriptions:        closes the file that is currently open
**
** Parameters:         	None
** Returned value:      None
**
*****************************************************************************/

void closeFile(){
	if (fp){
		errno_t err;
		err = fclose(fp);
		if (err == 0) printf("Closed File\n");
		else printf("Cannot close File\n");
	}
}

/*****************************************************************************
** Function name:       loadFile
**
** Descriptions:        loads the words into the dynamic array
**
** Parameters:         	None
** Returned value:      None
**
*****************************************************************************/

void loadFile(){
	int listCounter = 0, wordCounter = 0, charCounter = 0;
	char c;
	char temp[30];
	if (fp){
		list = malloc(sizeof(struct relation) * getLinesInFile());

		while ((c = getc(fp)) != EOF){
			if (c == ' '){
				temp[charCounter] = '\0';
				charCounter = 0;
				if (wordCounter % 2){
					strcpy(list[listCounter].translation, temp);
					wordCounter++;
					listCounter++;
				}else{
					strcpy(list[listCounter].word, temp);
					wordCounter++;
				}
			}
			else if(c != '\n') temp[charCounter++] = c;
		}	
	}else{
		printf("Can't load file, must restart program.\n");
	}
}

/*****************************************************************************
** Function name:       getLinesInFile
**
** Descriptions:        count amount of lines in file
**
** Parameters:         	None
** Returned value:      Returns an int with amount of lines in file
**
*****************************************************************************/

int getLinesInFile(){
	int lines = 0;
	char c;
	fseek(fp, 0, SEEK_SET);
	while ((c = getc(fp)) != EOF){
		if (c == '\n'){
			lines++;
		}
	}
	fseek(fp, 0, SEEK_SET);
	return amountOfWords = lines;
}

/*****************************************************************************
** Function name:       getAmountOfWords
**
** Descriptions:        returns amount of words in dictionary
**
** Parameters:         	None
** Returned value:      Returns an int with amount of words int memory
**
*****************************************************************************/

int getAmountOfWords(){
	return amountOfWords;
}

/*****************************************************************************
** Function name:       printHelp
**
** Descriptions:        prints the help file
**
** Parameters:         	None
** Returned value:      None
**
*****************************************************************************/

void printHelp(){

}