#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define DELIM " ,!¡¿?\'\"\n\t"
char *_strcat(char *dest, char *src);
int main(int ac, char **av, char **envp)
{
        char *prompt = "hola@shell$ ", *BUFFER;
        size_t bufsize = 1024;
        pid_t child_pid;
        char *token = NULL, *token2[1024];
        int reset, i;
        unsigned int getln;

        while (1)
        {
                i = 0;
                reset = 0;

                char path[60] = "/bin/";
                char path2[20] = "/sbin/";
                if (isatty(STDOUT_FILENO) == 1)
                        printf("$ ");
                printf("%s", prompt);

                getln = getline(&BUFFER, &bufsize, stdin);
                if (getln == EOF)
                {
                        printf("exit\n");
                        printf("\n");
                        exit(EXIT_SUCCESS);
                }

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
                                printf("\n-"); //PRODUCE DOS SALTOS DE LINEA
                                exit(0);
                        }
                }
                child_pid = fork();
                if (child_pid == -1)
                {
                        perror("Error");
                        return (1);
                }
                if (child_pid == 0)
                {
                        execve(_strcat(path, token2[0]), token2, NULL);
                        execve(_strcat(path2, token2[0]), token2, NULL);

                        exit(0);
                }
                else
                        child_pid = wait(NULL);
                for (;reset <= i; reset ++)
                        token2[reset] = NULL;
        }
        return (0);
}

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
