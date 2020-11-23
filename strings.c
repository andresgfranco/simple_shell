#include "header_minishell.h"
/**
  * _strcat - function to concatenate strings
  * @dest: destination string
  * @src: source string
  * Return: pointer of concatenated string
**/
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
	{
	}
	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}


/**
  * _strstr - function to find a string within another string
  * @haystack: string where we will search
  * @needle: string to find
  * Return: string found
**/
char *_strstr(char *haystack, const char *needle)
{
	char *c;
	while (*haystack)
	{
		while (*needle == *haystack)
		{
			haystack++, needle++;
		}
		if (*needle == '\0')
		{
			if(*haystack == '=')
			{
				haystack++;
				c = haystack;
				return c;
			}
			return (NULL);
		}
		haystack++;
	}
	return (NULL);
}
