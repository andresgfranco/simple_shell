#include "header_minishell.h"

char *_strcat(char *dest, char *src);

/**
  * main - main function where we receive the arguments
  * through the CLI
  * @ac: number of arguments
  * @av: arguments
  * @envp: environment pointer
  * Return: 0 if success
**/
int main(int ac, char **av, char **envp)
{
        char *prompt = "campo_gonzalez_shell$ ", *buffer,
	     *token = NULL, *token2[1024], path[60], path2[20];
        size_t bufsize = 1024;
        int reset, i;
        unsigned int getln;
	pid_t child_pid;

        while (1)
        {
                i = 0;
                reset = 0;
                path = "/bin/";
                path2 = "/sbin/";

                if (isatty(STDOUT_FILENO) == 1)
                        printf(GREEN_T "%s" RESET_COLOR, prompt);

                getln = getline(&buffer, &bufsize, stdin);
                if (getln == EOF)
                {
                        _puts("exit\n");
                        _puts("\n");
                        exit(EXIT_SUCCESS);
                }
		
                token = strtok(buffer, DELIM);
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
                                _puts("\n-"); //PRODUCE DOS SALTOS DE LINEA
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
