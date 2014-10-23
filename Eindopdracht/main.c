
#include <stdio.h>
#include "dictionary.h"
//#define USE_POINTER

int main(){
	openFile("dictionary.txt");
	loadFile();
	int i = 0;
	for (i = 0; i < getAmountOfWords()-1; i++){
		printf("%s %s\n", list[i].word, list[i].translation);
	}
	deleteWord("mouse");
	for (i = 0; i < getAmountOfWords() - 1; i++){
		printf("%s %s\n", list[i].word, list[i].translation);
	}
	addWord("drink", "drinken");
	closeFile();
	return 0;
}