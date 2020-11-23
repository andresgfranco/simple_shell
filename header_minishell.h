#ifndef HEADER_MINI_SHELL_
#define HEADER_MINI_SHELL_


/**---Libraries---**/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**---Prototypes functions to print---**/
void _puts(char *str);
int _putchar(char c);

/**---Prototypes functions to handle PATH and environment variables---**/
char **_getpath(const char *name);
char *_getenv(const char *name);

/**---Prototypes functions to handle strings---**/
char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, const char *needle);

/**---Delimitator---**/
#define DELIM " ,!¡¿?\'\"\n\t"

/**---Global variable environ---**/
extern char **environ;


#endif
