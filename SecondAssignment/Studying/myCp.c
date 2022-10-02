#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define RET 0
#define MAX_SIZE 10000

int main(int argv,char ** argc)
{
	printf("Copying program start.\n");
	if(argv<3){
		printf("There is no arguments.\n");
		return -1;
	}
	char buffer[MAX_SIZE];
	int flagSourceFile=open(argc[1],O_RDONLY);
	// check on flag
	if(flagSourceFile<0){
		printf("Source file is not exists.\n");
		return -1;
	}
	int flagDestinationFile=open(argc[2],O_WRONLY|O_CREAT,S_IRWXU|S_IRWXG|S_IRWXO);
	// check on flag
       if(flagDestinationFile<0){
                printf("Can't create a destination file.\n");
                return -1;
        }
	int countFlag=read(flagSourceFile,buffer,MAX_SIZE);
	// check on flag
	if(countFlag<0){
		printf("Error in reading source file.\n");
		return -1;
	}
	int writeFlag=write(flagDestinationFile,buffer,countFlag);
	// check on flag
      if(writeFlag<0){
                printf("Error in writing destinaiton file.\n");
                return -1;
        }
      countFlag=read(flagSourceFile,buffer,MAX_SIZE);
	while(countFlag>0){
		writeFlag=write(flagDestinationFile,buffer,countFlag);
        // check on flag
      	if(writeFlag<0){
                printf("Error in writing destinaiton file.\n");
                return -1;
        }
	countFlag=read(flagSourceFile,buffer,MAX_SIZE);
	}
      	int closeSourceFileFlag=close(flagSourceFile);
	// check on flag
	if(closeSourceFileFlag<0){
		printf("Error in closing source file.\n");
		return -1;
	}
     	 int closeDestinationFileFlag=close(flagDestinationFile);
	// check on flag
	if(closeDestinationFileFlag<0){
		printf("Error in closing destination file.\n");
		return -1;
	}

	printf("Program is finished\n");
	return RET;
}
