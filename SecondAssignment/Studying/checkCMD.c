#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define RET 0
#define MAX_SIZE 100

int main()
{
	printf("myEcho program start\n");
	//returnValue = write(Systemcl id,buffer string ,bufferCount);
	char strBuffer[MAX_SIZE];
	strcpy(strBuffer,"Hello my linux\n");
	int charCount=strlen(strBuffer);
	int flagOpenFile=open("./open_myECHO.txt",O_WRONLY);
	if(flagOpenFile<0)
	{
		printf("Error on openning file, So will create a new one. \n");
		flagOpenFile=open("./open_myECHO.txt",O_WRONLY|O_CREAT,S_IRWXU|S_IRWXG|S_IRWXO);
		printf("File ID = %d \n",flagOpenFile);
	}
	else if(flagOpenFile>0)
		printf("File is opened successfully, File ID = %d \n",flagOpenFile);
	write(flagOpenFile,strBuffer,charCount);
	int flagCloseFile=close(flagOpenFile);
	if(flagCloseFile<0)
		printf("Error closing file\n");
	else
		printf("Closing file successfully\n");
	//write(1,strBuffer,charCount);
	

	printf("Program is finished\n");
	return RET;
}
