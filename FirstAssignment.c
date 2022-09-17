#include <stdio.h>
#include <string.h>
#define MAX_Limit	1000

int main()
{
	char str[MAX_Limit];
	char exit[]="exit";
	int i=0;
	while(1)
	{
		printf("Enter your statment:");
		fgets(str,MAX_Limit,stdin);
		printf("%s\n",str);
		for(i=0;i<4;i++)
		{
			if(str[i]==exit[i])
				continue;
			else
				break;
		}
		if(i==4)
		{
			printf("Exiting, Goodbye");
			return 0;
		}
	}
	return 0;
}
