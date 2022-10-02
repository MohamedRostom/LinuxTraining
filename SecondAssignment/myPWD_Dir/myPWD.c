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
    printf("Getting my working path program start\n");
    char buffer[MAX_SIZE];
    printf("pwd: %s.\n", getcwd(buffer, MAX_SIZE));
    //printf("buffer: %s.\n",buffer);
    /*printf("argv = %d \n",argv); */

    printf("Program is finished\n");
    return RET;
}
