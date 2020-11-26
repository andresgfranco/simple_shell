#include  "header_minishell.h"
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
	char *prompt = "caribbean@shell$ ", *buffer = NULL, *mypath = NULL,
	**tokenized = NULL;
	size_t bufsize = 1024;
	char *command = NULL;
	int getln;

	while (1)
	{
		if (isatty(STDOUT_FILENO) == 1)
			_puts(prompt);
		getln = getline(&buffer, &bufsize, stdin);
		if (getln == EOF)
		{
			free(buffer);
			printerror(1, NULL);
			exit(0);
		}
		tokenized = tokenize(buffer);
		if (tokenized[0] != NULL)
		{
			execucion2(tokenized, command, mypath, buffer);
		}
		else
		{
			free(tokenized);
		}
	}
	(void)ac;
	(void)tokenized;
	(void)av;
	(void)envp;
	(void)*prompt;
	return (0);
}
