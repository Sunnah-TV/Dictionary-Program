
#include <stdio.h>
//#define USE_POINTER

int main(){
	openFile("dictionary.txt");
	loadFile();
	addword("drink", "drinken");
	closeFile();
	return 0;
}