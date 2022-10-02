#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define RET 0
#define MAX_SIZE 100

int main(int argv,char ** argc)
{
	printf("Checking argments program start\n");
	printf("argv = %d \n",argv);
	if(argv<=1)
		printf("There is no arguments\n");
	else{
		for(int i=0;i<argv;i++)
		{
			printf("argume number[%d] : %s \n",i,argc[i]);
		}
	}
	printf("Program is finished\n");
	return RET;
}
