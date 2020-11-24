#include "header_minishell.h"

/**
  * _getenv - function to print the environment variable
  * @name: command coming
  * Return: environment variable
**/

char *_getenv(const char *name)
{
	char *mi_envp;
	int index = 0;

	while (environ[index] != '\0')
	{
		mi_envp = _strstr(environ[index], name);
		if (mi_envp == NULL)
			index++;
		else
			return (mi_envp);
	}
	return (NULL);
}

/**
  * tokenize - functino to tokenize the command given
  * @buffer: command given
  * Return: array of strings tokenized
**/
char **tokenize(char *buffer)
{
	int i;
	char *token, **token2;

	token = strtok(buffer, DELIM);
	token2 = malloc(sizeof(char *) * (30));

	while (token != NULL)
	{
		token2[i] = (char *)malloc(sizeof(char) * (_strlen(token + 1)));
		token2[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	return (token2);
}

/**
 * _strlen - returns the lenght of a string
 * @s: string coming
 * Return: lenght of a string
 **/
int _strlen(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
	{
	}
	return (l);
}

/**
  * process_execution - function to run a child process
  * @childpid: child pid after fork in main
  * @tokenized: array of strings already tokenized
  * @path: path
  * @path2: path2
  * Return: void
**/
void process_execution(int ch_pid, char **tokenized, char *path, char *path2)
{
	if (ch_pid == -1)
	{
		_puts("Error");
	}
	if (ch_pid == 0)
	{
		if ((execve(tokenized[0], tokenized, NULL)) == -1)
		{
			execve(_strcat(path, tokenized[0]), tokenized, NULL);
			execve(_strcat(path2, tokenized[0]), tokenized, NULL);
		}
	}
	else
		ch_pid = wait(NULL);
}
