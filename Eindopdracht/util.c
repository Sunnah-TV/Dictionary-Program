#include "util.h"

int getArrayLength(struct relation **charArray){
	return (int)(sizeof(*charArray) / sizeof(charArray[0]));
}

int getSizeOf(struct relation charArray[]){
	return (int) sizeof(charArray);
}

int getSiz(){
	return (int) (sizeof(*list)/sizeof(struct relation));
}