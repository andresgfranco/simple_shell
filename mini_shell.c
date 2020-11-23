#include "header_minishell.h"
/**
  * main - main function of our shell that will
  * receive the arguments in an infinite loop
  * @ac: number of arguments
  * @av: arguments
  * @envp: environment variables
  * Return: 0 if success
**/

int main(int ac, char **av, char **envp)
{
	char *prompt = "hola@shell$ ", *BUFFER;
	size_t bufsize = 1024;
	pid_t child_pid;
	char *token = NULL, *token2[1024];
	int reset, i, b;
	unsigned int getln;
	char **mi_envp, *mypath, path[60] = "/bin/", path2[60] = "/sbin/", *path_str;

	while (1)
	{
		i = 0;
		reset = 0;		
		if (isatty(STDOUT_FILENO) == 1)
			printf(GREEN_T "%s" RESET_COLOR, prompt);		
		getln = getline(&BUFFER, &bufsize, stdin);
		if (getln == EOF)
		{
			printf("exit\n");
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		token = strtok(BUFFER, DELIM);
		//newenviron();
		mi_envp = _getpath("PATH");
		mypath = _getenv("PAT");
		while (token != NULL)
		{
			token2[i] = token;
			token = strtok(NULL, DELIM);
			i++;
		}
		if (token2[0] != NULL)
		{
			if(strcmp(token2[0], "exit") == 0)
			{
				printf("\n-"); 
				exit(0);
			}
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(_strcat(path, token2[0]), token2, NULL);
			execve(_strcat(path2, token2[0]), token2, NULL);
			exit(0);
		}
		else
			child_pid = wait(NULL);
		for (;reset <= i; reset ++)
			token2[reset] = NULL;
	}
	return (0);
}
