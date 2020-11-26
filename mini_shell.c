#include  "header_minishell.h"
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
        char *prompt ="caribbean@shell$ ", *buffer = NULL, *mypath = NULL, **tokenized = NULL;
        size_t bufsize = 1024;
        pid_t child_pid;
        int getln;

        while (1)
        {
                if (isatty(STDOUT_FILENO) == 1)
                        _puts(prompt);
                getln = getline(&buffer, &bufsize, stdin);
                if (getln == EOF)
                {
                        free(buffer);
                        printerror(1, NULL);
                        exit(0);
                }
                tokenized = tokenize(buffer);

                if (tokenized[0] != NULL && (_strcmp(tokenized[0], "exit") == 0))
                {
                        _puts("\n");
                        free_grid(tokenized);
                        free(buffer);
                        exit(0);
                }
                mypath = _getenv("PATH");
                child_pid = fork();
                if (child_pid == -1)
                {
                        return (-1);
                }
                if (child_pid == 0)
                {

                        execution(tokenized, mypath);
                        free_grid(tokenized);
                        exit(0);
                }
                else
                {
                        wait(NULL);
                }
                free_grid(tokenized);
        }
        (void)ac;
        (void)av;
        (void)envp;
        (void)*prompt;
        return (0);
}
