
#include <stdio.h>
#include "dictionary.h"
//#define _DEBUG
//#define USE_POINTER

int main(){
	FILE *fp = NULL;
	struct relation *list = NULL;
	
	openFile(&fp, "dictionary.txt");
	loadFile(&fp, &list);

	while (1){
		fflush(stdout);

		int input = 0, x=0;
		char inputString[30], inputString2[30];
		char address[100] = {0};
		printf("1: Search\n2: Add word\n3: Remove word\n4: Change word\n5: Print all words\n6: Print help\n7: Close program\n");
		x = scanf_s("%s", address, 2);
		fflush(stdin);

		switch (address[0]) {
		case '1':
			x = scanf_s("%99[a-zA-Z ]s", address, 99);
			printf("%d\t%s\n", x, address);
			translateWords(&list, address, sizeof(address)/sizeof(char));
			break;
		case '2':
			printf("Add word: ");
			scanf_s("%30s", inputString, 30);
			printf("with translation: ");
			scanf_s("%30s", inputString2, 30);
			addWord(&fp, &list, inputString, inputString2);
			break;
		case '3':
			printf("Remove word: ");
			x = getUserInput(inputString, sizeof(inputString));
			deleteWord(&fp, &list, inputString);
			break;
		case '4':
			printf("1: change word\n2: change translation\n");
			scanf_s("%1d", &input, 1);
			fflush(stdin);
			if (input == 1){
				printf("Change word: ");
				scanf_s("%30s", inputString, 30);
				printf("New word: ");
				scanf_s("%30s", inputString2, 30);
				changeWord(&fp, &list, inputString, inputString2);
			}else if (input == 2){
				printf("Change word: ");
				x = getUserInput(inputString, sizeof(inputString));
				printf("New translation: ");
				x = getUserInput(inputString2, sizeof(inputString2));
				changeTranslation(&fp, &list, inputString, inputString2);
			}
			break;
		case '5':
			printAll(&list);
			break;
		case '6':
			printHelp();
			break;
		case '7':
			closeDictionary(&fp, &list);
			return 0;
		}
	}
	return 0;
}