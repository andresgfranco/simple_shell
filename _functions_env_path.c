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
	while(environ[index] != '\0')
	{
		mi_envp = _strstr(environ[index], name);
		if (mi_envp == NULL)
			index++;
		else
			return mi_envp;
	}
	return NULL;
}

/**
  * _getpath - function to get the PATH environment variable
  * @name: command
  * Return: path
**/
char **_getpath(const char *name)
{
	char **mi_envp;
	int index = 0;
	mi_envp = malloc(sizeof(char *) * (100));
	for(index = 0;environ[index] != NULL; index++) 
	{
	}
	mi_envp = malloc(sizeof(char *) * (index));

	for(index = 0;environ[index] != NULL; index++) 
	{
		mi_envp[index] = (char *)malloc(sizeof(char) * (strlen(environ[index]) + 1));
		memcpy(mi_envp[index], environ[index], strlen(environ[index]));
	}
	return (mi_envp);
}
