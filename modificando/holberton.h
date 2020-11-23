#ifndef HEADER_FILE
#define HEADER_FILE

#include<string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
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
void  printenv(list_t **head, char *path);
char *_strstr(char *haystack, const char *needle); 
void free_list(list_t *head);
#endif
