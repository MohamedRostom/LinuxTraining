#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define RET 0
#define MAX_SIZE 1024

int main(int argv, char **argc)
{
    int progressCount = 0;

    printf("Copying program start.\n");
    // Checking on input arguments.
    if (argv < 3) {
	printf("There is no arguments.\n");
	return -1;
    }
    char buffer[MAX_SIZE];
    int flagSourceFile = open(argc[1], O_RDONLY);
    // Checking on opennig source file.
    if (flagSourceFile < 0) {
	printf("Source file is not exists.\n");
	return -1;
    }
    int flagDestinationFile = open(argc[2], O_WRONLY | O_CREAT, S_IRWXU);
    // Checking on openning or creating destination file.
    if (flagDestinationFile < 0) {
	printf("Can't create a destination file.\n");
	return -1;
    }
    int countFlag = read(flagSourceFile, buffer, MAX_SIZE);
    // Checking on reading source file.
    if (countFlag < 0) {
	printf("Error in reading source file.\n");
	return -1;
    }
    // Calculate progress
    progressCount += countFlag;
    int writeFlag = write(flagDestinationFile, buffer, countFlag);
    // Checking on writing in distination file.
    if (writeFlag < 0) {
	printf("Error in writing destinaiton file.\n");
	return -1;
    } else {
	printf("Copying file in progress (%d KB).\n", progressCount);
    }
    // Looping to read and write all data according to buffer size.
    while ((countFlag = read(flagSourceFile, buffer, MAX_SIZE)) > 0) {
	// Calculate progress
	progressCount += countFlag;
	writeFlag = write(flagDestinationFile, buffer, countFlag);
	// Checking on writing in distination file.
	if (writeFlag < 0) {
	    printf("Error in writing destinaiton file.\n");
	    return -1;
	} else {
	    printf("Copying file in progress (%d KB).\n", progressCount);
	}
    }
    int closeSourceFileFlag = close(flagSourceFile);
    // check on flag
    if (closeSourceFileFlag < 0) {
	printf("Error in closing source file.\n");
	return -1;
    }
    int closeDestinationFileFlag = close(flagDestinationFile);
    // check on flag
    if (closeDestinationFileFlag < 0) {
	printf("Error in closing destination file.\n");
	return -1;
    }

    printf("Program finished\n");
    return RET;
}
