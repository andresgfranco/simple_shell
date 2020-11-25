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
	     path[60] = "/bin/", path2[60] = "/sbin/", **tokenized;
	size_t bufsize = 1024;
	pid_t child_pid;
	int reset, i;
	int getln;

	while (1)
	{
		i = 0;
		reset = 0;
		if (isatty(STDOUT_FILENO) == 1)
			_puts(prompt);
		getln = getline(&buffer, &bufsize, stdin);
		if (getln == EOF)
			printerror(1, NULL);
		tokenized = tokenize(buffer);
		mypath = _getenv("PATH");
		if (tokenized[0] == NULL || (_strcmp(tokenized[0], "exit") == 0))
		{
			_puts("\n");
			exit(0);
		}
		child_pid = fork();
		process_execution(child_pid, tokenized, path, path2);
		for (; reset <= i; reset++)
			tokenized[reset] = NULL;
	}
	(void)ac;
	(void)av;
	(void)envp;
	return (0);
}
