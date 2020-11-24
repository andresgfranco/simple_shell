#include "holberton.h"
extern char **environ;
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

list_t  *printenv(list_t **head, char *path)
{
	//printf("printenv --- %s", path);
	char *token;
	int a = 0;
	char *temp  =  malloc(sizeof(char ) * (strlen(path) + 1));
	temp = strcpy(temp, path);
   	const char s[2] = ":";
   /* get the first token */
   	token = strtok(temp, s);
   
   /* walk through other tokens */
   while( token != NULL && a <= 20 ) 
	{
     // printf( "1 %s\n", token);
    	add_node_end(head, token);
      	token = strtok(NULL, s);
	a++;
	  }
	free(temp);
	return(*head);
}

list_t *add_node_end(list_t **head, char *str)
{
    list_t *new_node = (list_t *) malloc(sizeof(list_t));
    list_t *last = *head;

    if (new_node == NULL || str == NULL)
    {
        free(new_node);
        return (new_node);
    }
    new_node->str = strdup(str);
    new_node->len = len(str);
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return (*head);
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return (*head);
}

int len(const char *str)
{
    int count;

    if (str == NULL)
        return (0);
    for (count = 0; str[count] != '\0'; count++)
        ;
    return (count);
}

size_t print_list(const list_t *h, char *comando)
{
    unsigned int count = 0;

    if (h == NULL)
        return (0);
    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[%u] (nil)\n", h->len);
        else
	{
            	_strcat(h->str, "/");
		_strcat(h->str, comando);
	}
           // printf("[%u] %s\n", h->len, h->str);
        count += 1;
        h = h->next;
    }
    return (count);
}

void executar ( list_t *h, char **direcion)
{
    unsigned int count = 0;
	
    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[%u] (nil)\n", h->len);
	//printf("%s\n", h->str);
	execve(h->str, direcion, NULL);
        count += 1;
        h = h->next;
    }
}
void free_list(list_t *head)
{
        list_t *tmp;
        if (head == NULL)
        {
                return;
        }
        while (head != NULL)
        {
                tmp = head;
                free(tmp->str);
                free(tmp);
                head = head->next;
        }
}
char **tokenize(char *buffer)
{
	int i;
	char *token, **token2;
	
	token = strtok(buffer, DELIM);
	token2 = malloc(sizeof(char *) * (30));

	while (token != NULL)
	{
		token2[i] = (char*)malloc(sizeof(char) * (_strlen(token) + 1));
		token2[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	return (token2);
}
int _strlen(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
		{
	}
	return (l);
}
void process_execution(int child_pid, char **tokenized, list_t *h)
{
	if (child_pid == -1)
	{
		_puts("Error");
	}
	if (child_pid == 0)
	{
		if ((execve(tokenized[0], tokenized, NULL)) == -1)
		{
		/*
			execve(_strcat(path, tokenized[0]), tokenized, NULL);
			execve(_strcat(path2, tokenized[0]), tokenized, NULL);
		*/
		executar(h, tokenized);
		}
	}
	else
		child_pid = wait(NULL);
}
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
		if (s1[i] == '\0')
			return (0);
	return (s1[i] - s2[i]);
}
int _putchar(char c)
{
		return (write(1, &c, 1));
}
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
void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i] != NULL ; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
