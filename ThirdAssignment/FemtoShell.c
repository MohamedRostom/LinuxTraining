#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LIMIT 1000

int main(int argc, char *argv[])
{
	char str[MAX_LIMIT];
	char exit[] = "exit\n";

	int ret_pid = 0;
	int status;
	while (1) {
		
		printf("Femto Shell ~$ ");
		fgets(str, MAX_LIMIT, stdin);
		
		if (strcmp(str, exit) == 0) {
			printf("Exiting, Goodbye......... \n");
			return 0;
		}
		printf("The main PID =%d \n", getpid());
		
		ret_pid = fork();
		if (ret_pid < 0) {
			printf("Fork failed.\n");
		} 
		else if (ret_pid > 0) {
			printf("This is the parent. My child ID: %d, while my PID = %d \n",
			     ret_pid, getpid());
			wait(&status);
			printf("The child proccess terminated successfully.\n");
		} 
		else {
			printf("This is the child and its PID = %d, and the parent PID = %d \n",
			     getpid(), getppid());
			
			char *new_argv[10] = { NULL };
			char *new_envp[10] = { NULL };
			char *saveptr;
			char *token = strtok_r(str, " ", &saveptr);
			int i = 0;
			
			while (token != NULL) {
				new_argv[i] = token;
			
				if ((new_argv[i][strlen(new_argv[i]) - 1] ==
				     '\n')) {
					new_argv[i][strlen(new_argv[i]) - 1] =
					    0;
				}
				token = strtok_r(NULL, " ", &saveptr);
				i++;
			}
			
			// printf ("End of String.\n");
			execve(new_argv[0], new_argv, new_envp);
			printf("Error in execve command !\n");
			sleep(1);
		}
	}
	return 0;
}
