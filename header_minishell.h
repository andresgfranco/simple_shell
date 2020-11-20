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

/**---Prototypes functions to execute---**/


/**---Color to our mini-shell :) ---**/
#define GREEN_T "\x1b[32m"
#define RESET_COLOR "\x1b[37m"

/**---Delimitator---**/
#define DELIM " ,!¡¿?\'\"\n\t"

#endif
