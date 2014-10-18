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
		err = fopen_s(&fp, path, "w");
		if (err == 0) printf("Opened File %s\n", path);
		else printf("Cannot open File %s\n", path);
	}else{
		printf("File does not exist, created file %s\n", path);
		fp = fopen_s(&fp, path, "w");
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