#include "holberton.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define GREEN_T "\x1b[32m"
#define RESET_COLOR "\x1b[37m"

#define DELIM " ,!¡¿?\'\"\n\t"

extern char **environ;

int main(int ac, char **av, char **envp)
{
	 /*list_t i*head;
	head = NULL;*/
        char *prompt = "hola@shell$ ", *buffer;
        size_t bufsize = 1024;
        pid_t child_pid;
        char *token = NULL, *token2[1024];
        int reset, i, b;
        unsigned int getln;
	char **mi_envp;
	char *mypath, **tokenized;
        while (1)
	{
		list_t *head;
		head = NULL;
                i = 0;
                reset = 0;

                if (isatty(STDOUT_FILENO) == 1)
                        printf(GREEN_T "%s" RESET_COLOR, prompt);

                getln = getline(&buffer, &bufsize, stdin);
                if (getln == EOF)
                {
                        printf("exit\n");
                        printf("\n");
                        exit(EXIT_SUCCESS);
                }

                tokenized = tokenize(buffer);
		
                if (tokenized[0] != NULL)
                {
                        if(strcmp(tokenized[0], "exit") == 0)
                        {
                                printf("\n-"); 
                                exit(0);
                        }
                }

		mypath = _getenv("PATH");

		printenv(&head, mypath);
		
		 if (tokenized[0] != NULL){
		print_list(head,tokenized[0]);
		}
                child_pid = fork();

                if (child_pid == -1)
                {
                        perror("Error");
                        return (1);
                }
                if (child_pid == 0)
                {
			if ((execve(tokenized[0], tokenized, NULL)) == -1)
			{
				executar(head, tokenized);
			}
                }
                else
                        child_pid = wait(NULL);
        }
        return (0);
}
