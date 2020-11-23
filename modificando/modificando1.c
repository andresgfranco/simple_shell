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
        char *prompt = "hola@shell$ ", *BUFFER;
        size_t bufsize = 1024;
        pid_t child_pid;
        char *token = NULL, *token2[1024];
        int reset, i, b;
        unsigned int getln;
	char **mi_envp;
	char *mypath;
        while (1)
	{
		list_t *head;
		head = NULL;
                i = 0;
                reset = 0;

                if (isatty(STDOUT_FILENO) == 1)
                        printf(GREEN_T "%s" RESET_COLOR, prompt);

                getln = getline(&BUFFER, &bufsize, stdin);
                if (getln == EOF)
                {
                        printf("exit\n");
                        printf("\n");
                        exit(EXIT_SUCCESS);
                }
		/*for(b = 0; environ[b] != NULL; b++)
			printf("{%s}\n", environ[b]);*/

                token = strtok(BUFFER, DELIM);

                while (token != NULL)
                {
                        token2[i] = token;
                        token = strtok(NULL, DELIM);
                        i++;
                }
                if (token2[0] != NULL)
                {
                        if(strcmp(token2[0], "exit") == 0)
                        {
                                printf("\n-"); 
                                exit(0);
                        }
                }
		 
		mi_envp = _getpath("path");
		mypath = _getenv("PATH");
		printf("%s\n", mypath);
		printenv(&head, mypath);
		
		 if (token2[0] != NULL){
		print_list(head,token2[0]);
		}
                child_pid = fork();

                if (child_pid == -1)
                {
                        perror("Error");
                        return (1);
                }
                if (child_pid == 0)
                {
	               // execve(_strcat(path, token2[0]), token2, NULL);
                       // execve(_strcat(path2, token2[0]), token2, NULL);
			executar(head, token2);
			//free_list(head);
			//head = NULL;
			
                        printf("Hello World");
                }
                else
                        child_pid = wait(NULL);
		//free_list(head);
		//head = NULL;
		//mypath = NULL;
                for (;reset <= i; reset ++)
		{
			printf("hola\n");
                       // token2[reset] = NULL;
		}
        }
	printf("hola");
        return (0);
}
/*
char **newenviron(void)
{
	char **envp = environ;
        int index = 0;
	int count;
        for(index = 0;environ[index] != NULL; index++) 
	{
        }

	printf("---{%d}---", index);

	har *path)    )); 
	
        for(count = 0; count < (index + 1); count++) 
	{
        ////      environ[count] = realloc(environ, sizeof(char) * (strlen(environ[count]) + 20));
	}
	printf("count----%d\n----", count);
	return (environ);
}
*/
