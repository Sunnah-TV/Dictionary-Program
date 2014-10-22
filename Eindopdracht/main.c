
#include <stdio.h>
#include "dictionary.h"
//#define USE_POINTER

int main(){
	openFile("dictionary.txt");
	loadFile();
	/*int i = 0;
	for (i = 0; i < getLinesInFile(); i++){
		printf("%s %s\n", list[i].word, list[i].translation);
	}*/

	printf("%d\n", getSiz());
	printf("%d\n", getArrayLength(list));
	printf("%d\n", getSizeOf(list));

	//addword("drink", "drinken");
	closeFile();
	return 0;
}