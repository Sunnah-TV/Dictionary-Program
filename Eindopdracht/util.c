#include "util.h"

int getUserInput(char *returnStr, int maxStringLength)
{
	char *tempStr;
	int totalCount = 0, overflow = 0;
	size_t len;
	tempStr = malloc((maxStringLength + 2) * sizeof(char));
	do {
		fgets(tempStr, maxStringLength + 1, stdin);
		len = strlen(tempStr);
		if (tempStr[len - 1] == '\n') {
			tempStr[len - 1] = '\0';
			len = strlen(tempStr);
		}
		if (!overflow++)
		strcpy_s(returnStr, maxStringLength, tempStr);
		totalCount += (int)len;
	} while ((int)len == maxStringLength);
	free(tempStr);
	return totalCount;
}