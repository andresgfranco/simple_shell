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
	char *prompt = "caribbean@shell$ ", *buffer, *mypath,
	     **tokenized;
	size_t bufsize = 1024;
	pid_t child_pid;
	int getln;

	while (1)
	{
		if (isatty(STDOUT_FILENO) == 1)
			_puts(prompt);
		getln = getline(&buffer, &bufsize, stdin);
		if (getln == EOF)
			printerror(1, NULL);
		tokenized = tokenize(buffer);
		if (tokenized[0] == NULL || (_strcmp(tokenized[0], "exit") == 0))
		{
			_puts("\n");
			exit(0);
		}
		mypath = _getenv("PATH");
		child_pid = fork();
		if (child_pid == -1)
			return -1;
		if (child_pid == 0)
		{
			execution(tokenized, mypath);
		}
		else
			wait(NULL);
		free_grid(tokenized);
	}
	(void)ac;
	(void)av;
	(void)envp;
	return (0);
}
