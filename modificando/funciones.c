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
		
		printf("getenv; %s\n", mi_envp);
		if (mi_envp == NULL)
			index++;
		else
			return NULL;
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

void  printenv(list_t **head, char *path)
{
   char *token;
   const char s[2] = ":";
printf("%s\n", path);
   /* get the first token */
   token = strtok(path, s);
   
   /* walk through other tokens */
   while( token != NULL ) 
	{
      printf( "1%s\n", token );
    add_node_end(head, token);

      printf( "2%s\n", token );
      token = strtok(NULL, s);
	}
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
            //printf("[%u] %s\n", h->len, h->str);
        count += 1;
        h = h->next;
    }
    return (count);
}

void executar (list_t *h, char **direcion)
{
    unsigned int count = 0;
	
    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[%u] (nil)\n", h->len);
	printf("%s\n", h->str);
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
