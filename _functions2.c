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
	int words, i = 0;
	char *token, **token2;
	words = count_words(buffer);
	if(words == 0)
	{
		return NULL;
	}

	token = strtok(buffer, DELIM);
	token2 = malloc(sizeof(char *) * (words + 1));

	while (token != NULL)
	{
		token2[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		token2[i] = strcpy(token2[i], token);
		token = strtok(NULL, DELIM);
		i++;
	}
	token2[i] = NULL;
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
 * execution - function to execute child process
 * @tokeni: tokenized array
 * @path: path
 * Return: void
**/
void execution(char **tokeni, char *path)
{	
	char *token = NULL, *combinar = NULL, *temp = NULL;
	const char s[2] = ":";
	struct stat st;

	if (stat(tokeni[0], &st) == 0)
	{
		execve(tokeni[0], tokeni, NULL);
	}
	else
	{
		temp  =  malloc(sizeof(char ) * (_strlen(path) + 1));
		temp = _strcpy(temp, path);
		token = strtok(temp, s);
		while( token != NULL )
		{
			combinar = malloc(sizeof(char) * (_strlen(token) + _strlen(tokeni[0]) + 2));
			combinar = _strcpy(combinar, token);
			combinar = _strcat(combinar, tokeni[0]);
			execve(combinar, tokeni, NULL);
			token = strtok(NULL, s);
			free(combinar);
		}
		free(temp);
	}
}
