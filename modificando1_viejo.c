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

char *_strcat(char *dest, char *src);
char *_strstr(char *haystack, const char *needle);
char **_getpath(const char *name);
char *_getenv(const char *name);
//char **newenviron(void);

int main(int ac, char **av, char **envp)
{

        char *prompt = "hola@shell$ ", *BUFFER;
        size_t bufsize = 1024;
        pid_t child_pid;
        char *token = NULL, *token2[1024];
        int reset, i, b;
        unsigned int getln;
	char **mi_envp;
	char *mypath;
	char path[60] = "/bin/";
	char path2[60] = "/sbin/";
        while (1)
        {
                i = 0;
                reset = 0;
		char *path_str = (char *)malloc(sizeof(char) * 256);	

                if (isatty(STDOUT_FILENO) == 1)
                        printf(GREEN_T "%s" RESET_COLOR, prompt);

                getln = getline(&BUFFER, &bufsize, stdin);
                if (getln == EOF)
                {
                        printf("exit\n");
                        printf("\n");
                        exit(EXIT_SUCCESS);
                }

                token = strtok(BUFFER, DELIM);

		//newenviron();

		mi_envp = _getpath("PATH");
		mypath = _getenv("PAT");
		printf("my path = {%s}\n", mypath);

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

char *_getenv(const char *name)
{

	char *mi_envp;
        int index = 0;
	while(environ[index] != '\0')
	{
		mi_envp = _strstr(environ[index], name);
		if (mi_envp == NULL)
			index++;
		else
			return mi_envp;
       	}
	return NULL;
}

char **_getpath(const char *name)
{
	char **mi_envp;
        int index = 0;
	mi_envp = malloc(sizeof(char *) * (100));
        for(index = 0;environ[index] != NULL; index++) 
	{
        }
	mi_envp = malloc(sizeof(char *) * (index));

        for(index = 0;environ[index] != NULL; index++) 
	{
                mi_envp[index] = (char *)malloc(sizeof(char) * (strlen(environ[index]) + 1));
                memcpy(mi_envp[index], environ[index], strlen(environ[index]));
	}
	return (mi_envp);
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

	envp = realloc(envp, ((index + 1) * sizeof(char))); 
	
        for(count = 0; count < (index + 1); count++) 
	{
        ////      environ[count] = realloc(environ, sizeof(char) * (strlen(environ[count]) + 20));
	}
	printf("count----%d\n----", count);
	return (environ);
}
*/
