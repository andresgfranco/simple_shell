#include "holberton.h"
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
        char *prompt = "hola@shell$ ", *buffer;
        size_t bufsize = 1024;
        pid_t child_pid;
        int reset, i, b;
        unsigned int getln;
	char *mypath, **tokenized;
        while (1)
	{
		list_t *head;
		head = NULL;
                i = 0;
                reset = 0;
                if (isatty(STDOUT_FILENO) == 1)
                        _puts(prompt);
                getln = getline(&buffer, &bufsize, stdin);
                if (getln == EOF)
                {
                        printerror(1, NULL);
                }
                tokenized = tokenize(buffer);
                if (tokenized[0] != NULL && (_strcmp(tokenized[0], "exit") == 0) )
                {
                                printf("\n-"); 
                                exit(0);
                }
		mypath = _getenv("PATH");
		printenv(&head, mypath);
		if (tokenized[0] != NULL){
			print_list(head,tokenized[0]);
		}
                child_pid = fork();
		process_execution(child_pid, tokenized, head);
		printf("hola\n");
	
		free_list(head);
		head = NULL;

		/*for(i = 0; tokenized[i] != NULL; i++)
		{*/
		//}

		
		//free(mypath);
        }
	
	free(buffer);
	free(tokenized);
        return (0);
}
