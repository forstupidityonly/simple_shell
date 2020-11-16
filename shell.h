#ifndef SHELL_H
#define SHELL_H

/*____ HEADERS ____*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

/*____ STRUCTURES _____*/

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

/*_____ PROTOTYPES ____*/

extern char **environ;
char *_strcpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_getenv(char *name);
/* size_t print_list(const list_t *h); */
list_t *path_tok(char *s, list_t *node);
list_t *add_node(list_t **node, const char *token);
void free_list(list_t *head);
DIR *search_dir(list_t *head, char *buffer);
int _strlen(char *s);

#endif
