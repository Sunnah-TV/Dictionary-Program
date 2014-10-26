
#include <stdio.h>
#include "dictionary.h"
//#define USE_POINTER

int main(){
	openFile("dictionary.txt");
	loadFile();
	while (1){
		int input = 0;
		char inputString[30], inputString2[30];
		printf("1: Add word\n2: Remove word\n3: Change word\n4: Print all words\n5: Print help\n6: Close program\n");
		scanf_s("%1d", &input, 1);

		switch (input) {
		case 1:
			printf("Add word: ");
			scanf_s("%29s", inputString, 30);
			printf(", with translation: ");
			scanf_s("%29s", inputString2, 30);
			addWord(inputString, inputString2);
			break;
		case 2:
			printf("Remove word: ");
			scanf_s("%29s", inputString, 30);
			deleteWord(inputString);
			break;
		case 3:
			printf("1: change word\n2: change translation\n");
			scanf_s("%1d", &input, 1);
			if (input == 1){
				printf("Change word: ");
				scanf_s("%29s", inputString, 30);
				printf("New word: ");
				scanf_s("%29s", inputString2, 30);
				changeWord(inputString, inputString2);
			}else if (input == 2){
				printf("Change word: ");
				scanf_s("%29s", inputString, 30);
				printf("New translation: ");
				scanf_s("%29s", inputString2, 30);
				changeTranslation(inputString, inputString2);
			}
			break;
		case 4:
			printAll();
			break;
		case 5:
			printHelp();
			break;
		case 6:
			closeDictionary();
			return 0;
		}
	}
	return 0;
}