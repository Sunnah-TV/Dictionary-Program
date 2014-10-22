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
	if (fp){
		list = (struct relation *) malloc(sizeof(struct relation) * getLinesInFile());

		while ((c = getc(fp)) != EOF){
			if (c == ' '){
				list[listCounter].word[charCounter] = '\0';//string end indicator
				wordCounter++;
				charCounter = 0;
			}else if (c == '\n'){
				list[listCounter].translation[charCounter] = '\0';//string end indicator
				listCounter++;
				wordCounter++;
				charCounter = 0;
			}else{
				if (wordCounter % 2 == 0){
					list[listCounter].word[charCounter] = c;
					charCounter++;
				}else{
					list[listCounter].translation[charCounter] = c;
					charCounter++;
				}
			}
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
	printf("%d\n", lines);
	fseek(fp, 0, SEEK_SET);
	return lines;
}