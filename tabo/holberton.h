#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#define DELIM " ,!¡¿?\'\"\n\t"
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h, char *comando);
char *_strcat(char *dest, char *src);
char **_getpath(const char *name);
char *_getenv(const char *name);
list_t *add_node_end(list_t **head, char *str);
int len(const char *str);
void executar ( list_t *h, char **direcion);
list_t  *printenv(list_t **head, char *path);
char *_strstr(char *haystack, const char *needle); 
void free_list(list_t *head);
char **tokenize(char *buffer);
int _strlen(char *s);
void process_execution(int child_pid, char **tokenized, list_t *h);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);
void printerror(int error, char *command);
void free_grid(char **grid);
#endif
