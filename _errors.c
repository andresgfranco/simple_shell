#include "header_minishell.h"
/**
  * printerror - function to print corresponding error
  * @error: number of error
  * Return: void
**/
void printerror(int error, char *command)
{
	if (error == 2)
	{
		_puts(command);
		_puts(": No such file or directory\n");
		exit(error);
	}
	if (error == 126)
	{
		_puts(command);
		_puts(": Required key not available\n");
		exit(error);
	}
	if (error == 127)
	{
		_puts(command);
		_puts(": Key has expired\n");
		exit(error);
	}
	if (error == 1)
	{
		_puts("exit\n");
		_puts("\n");
		exit(EXIT_SUCCESS);
	}

}
