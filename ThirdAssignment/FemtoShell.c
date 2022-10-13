#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_LIMIT 100
#define OVERWRITE 1

int separateArguments(char str[], char *argv[]);
int storeLocalVariables(char *argv[], char **localVariables[]);
int storeImportedLocalVariables(const char *argName,const char *argValue , char **LocalVariables[]);
int exportingLocalVariable(const char *input, char ***localVariables);
int getLocalVariable(const char *input, char ***localVariables);
int gettingEnvVariable(const char *input, char ***localVariables);

unsigned int localVariableIndex = 0;
// extern char ** environ;

int main(int argc, char *argv[], char *envp[])
{
	char promptCMD[MAX_LIMIT];
	getcwd(promptCMD, MAX_LIMIT);

	char str[MAX_LIMIT];
	char exit[] = "exit\n";

	int ret_pid = 0;
	int status;
	char *new_envp[10] = {NULL};

	char ***LocalVariables = (char ***)malloc(MAX_LIMIT * sizeof(char **));
	for (int i = 0; i < MAX_LIMIT; i++)
	{
		LocalVariables[i] = (char **)malloc(MAX_LIMIT * sizeof(char *));
		for (int j = 0; j < 2; j++)
		{
			LocalVariables[i][j] = (char *)malloc(MAX_LIMIT * sizeof(char));
		}
	}

	while (1)
	{
		char *new_argv[MAX_LIMIT] = {NULL};
		int variableFlag = 0;
		int storingVariableFlag = 0;

		printf("Femto Shell ~$ ");
		// printf("%s ~$ ",promptCMD);
		fgets(str, MAX_LIMIT, stdin);

		if (strcmp(str, exit) == 0)
		{
			printf("Exiting, Goodbye......... \n");
			for (int i = 0; i < MAX_LIMIT; i++)
			{
				free(LocalVariables[i]);
			}
			return EXIT_SUCCESS;
		}
		else if (strcmp(str, "\n") == 0)
		{
			continue;
		}
		else
		{
			variableFlag = separateArguments(str, new_argv);
		}

		if (variableFlag == EXIT_SUCCESS)
		{
			storingVariableFlag = storeLocalVariables(new_argv, LocalVariables);
			if (storingVariableFlag != EXIT_SUCCESS)
			{
				printf("Error while storing a local variable.\n");
			}
		}
		// Return local variables
		else if (strcmp(new_argv[0], "set") == 0)
		{
			for (int j = 0; j < localVariableIndex; j++)
			{
				// printf("local_vars[%d] : %s = %s \n", j, new_envp[j], getenv(new_envp[j]));
				printf("local_vars[%d] : %s = %s \n", j, LocalVariables[j][0], LocalVariables[j][1]);
			}
			continue;
		}
		else if (strcmp(new_argv[0], "export") == 0)
		{
			// printf("export CMD \n");
			// The getenv() function searches the environment list to find the environment variable name, and returns a pointer to the corresponding value string
			if ((new_argv[1] == NULL) || (new_argv[1] == "\n"))
			{
				printf("Not enough arguments !\n");
				continue;
			}
			int resultFlag = exportingLocalVariable(new_argv[1], LocalVariables);
			if (resultFlag != EXIT_SUCCESS)
			{
				printf("Error in exporting\n");
			}
			continue;
		}
		else if (strcmp(new_argv[0], "get") == 0)
		{
			// printf("export CMD \n");
			// The getenv() function searches the environment list to find the environment variable name, and returns a pointer to the corresponding value string
			if ((new_argv[1] == NULL) || (new_argv[1] == "\n"))
			{
				printf("Not enough arguments !\n");
				continue;
			}
			int resultIndex = getLocalVariable(new_argv[1], LocalVariables);
			if (resultIndex != -1)
			{
				printf("local_vars[%d] : %s = %s \n", resultIndex, LocalVariables[resultIndex][0], LocalVariables[resultIndex][1]);
			}
			else
			{
				printf("Enter variable is not saved in the local variables !\n");
			}
			continue;
		}
		else if (strcmp(new_argv[0], "getenv") == 0)
		{
			if ((new_argv[1] == NULL) || (new_argv[1] == "\n"))
			{
				printf("Not enough arguments !\n");
				continue;
			}
			int resultCode = gettingEnvVariable(new_argv[1],LocalVariables);
			if(resultCode==EXIT_SUCCESS){
				printf("Result code (%d) Done searching in env variables.\n",resultCode);
			}
			else{
					printf("Result code (%d) Error during searching in env variables.\n",resultCode);
			}
			continue;
		}
		else
		{
			// printf("The main PID =%d \n", getpid());

			ret_pid = fork();
			if (ret_pid < 0)
			{
				printf("Fork failed.\n");
			}
			else if (ret_pid > 0)
			{
				// printf("This is the parent. My child ID: %d, while my PID = %d \n",ret_pid, getpid());
				wait(&status);
				if (WIFEXITED(status))
				{
					// printf("Result code : %d .\n",WEXITSTATUS(status));
					if (WEXITSTATUS(status) == 0)
					{
						printf("\nResult code : %d, Process run and terminated successfully.\n", WEXITSTATUS(status));
					}
					else if (WEXITSTATUS(status) == 1)
					{
						printf("\nResult code : %d, Error during process run but terminated successfully.\n", WEXITSTATUS(status));
					}
					else
					{
						printf("\nResult code : %d, UNEXPECTED RESULT CODE!.\n", WEXITSTATUS(status));
					}
				}
				// printf("The child proccess terminated successfully.\n");
			}
			else
			{
				// printf("This is the child and its PID = %d, and the parent PID = %d \n\n", getpid(), getppid());
				execvp(new_argv[0], new_argv);
				printf("Error while running the input command !\n");
				return EXIT_FAILURE;
			}
		}
	}
	return EXIT_SUCCESS;
}

int separateArguments(char str[], char *argv[])
{
	char *saveptr;
	char *token = strtok_r(str, " ", &saveptr);
	int i = 0;
	unsigned int variableFlag = EXIT_FAILURE;
	while (token != NULL)
	{
		argv[i] = token;
		// printf("1.Argument[%i] : %s\n",i,argv[i]);
		if ((argv[i][strlen(argv[i]) - 1] == '\n'))
		{
			argv[i][strlen(argv[i]) - 1] = 0;
			// printf("2.Argument[%i] : %s\n",i,argv[i]);
		}
		if ((strstr(argv[i], "=")))
		{
			char *temp = strtok(argv[i], "=");
			while (temp != NULL)
			{
				argv[i] = temp;
				temp = strtok(NULL, "=");
				i++;
			}
			variableFlag = EXIT_SUCCESS;
		}
		token = strtok_r(NULL, " ", &saveptr);
		i++;
	}
	return variableFlag;
}

int storeLocalVariables(char *argv[], char **LocalVariables[])
{
	int resultFlag = EXIT_FAILURE;
	if ((argv[0] == NULL) || (argv[1] == NULL) || (argv[0] == "\n") || (argv[1] == "\n"))
	{
		printf("Not enough input arguments !\n");
		return EXIT_FAILURE;
	}
	else
	{
		for (int i = 0; i < localVariableIndex; i++)
		{
			if (strcmp(LocalVariables[i][0], argv[0]) == 0)
			{
				strcpy(LocalVariables[i][1], argv[1]);
				return EXIT_SUCCESS;
			}
		}
		strcpy(LocalVariables[localVariableIndex][0], argv[0]);
		strcpy(LocalVariables[localVariableIndex][1], argv[1]);
		localVariableIndex++;
		resultFlag = EXIT_SUCCESS;
	}
	return resultFlag;
}

int exportingLocalVariable(const char *input, char ***localVariables)
{
	int exitFlag = EXIT_FAILURE;
	// printf("Input : %s\n", input);
	for (int i = 0; i < localVariableIndex && exitFlag != 0; i++)
	{
		if (strcmp(input, localVariables[i][0]) == 0)
		{
			// printf("Value founded XD\n");
			exitFlag = setenv(localVariables[i][0], localVariables[i][1], OVERWRITE);
			return exitFlag;
		}
	}
	printf("Not existing variable in local varibales !\n");
	return exitFlag;
}

int getLocalVariable(const char *input, char ***localVariables)
{
	int exitFlag = -1;
	// printf("Input : %s\n", input);
	for (int i = 0; i < localVariableIndex && exitFlag != 0; i++)
	{
		if (strcmp(input, localVariables[i][0]) == 0)
		{
			return i;
		}
	}
	printf("Not existing variable in local varibales !\n");
	return exitFlag;
}

int gettingEnvVariable(const char *input, char ***LocalVariables)
{
	char *result = getenv(input);
	if (result == NULL)
	{
		printf("Entered variable is not saved in envirnment variables !\n");
		return EXIT_FAILURE;
	}
	else
	{
		// strcpy(LocalVariables[localVariableIndex][0], input);
		// strcpy(LocalVariables[localVariableIndex][1], result);
		// localVariableIndex++;
		printf("%s = %s\n", input, result);
		int resultFlag = storeImportedLocalVariables(input,result,LocalVariables);
		if(resultFlag!=EXIT_SUCCESS){
			printf("Error in exporting environment variable !\n");
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

int storeImportedLocalVariables(const char *argName,const char *argValue , char **LocalVariables[])
{
	int resultFlag = EXIT_FAILURE;
	if ((argName == NULL) || (argValue == NULL) || (argName == "\n") || (argValue == "\n"))
	{
		printf("Not enough input arguments !\n");
		return EXIT_FAILURE;
	}
	else
	{
		for (int i = 0; i < localVariableIndex; i++)
		{
			if (strcmp(LocalVariables[i][0], argName) == 0)
			{
				strcpy(LocalVariables[i][1], argValue);
				return EXIT_SUCCESS;
			}
		}
		strcpy(LocalVariables[localVariableIndex][0], argName);
		strcpy(LocalVariables[localVariableIndex][1], argValue);
		localVariableIndex++;
		resultFlag = EXIT_SUCCESS;
	}
	return resultFlag;
}