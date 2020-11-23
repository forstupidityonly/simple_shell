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
#include <errno.h>

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
extern int errno;
char *_strcpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strcmp_exact(char *s1, char *s2);
char *_strdup(char *str);
char *_getenv(char *name);
/*size_t print_list(const list_t *h);*/
list_t *path_tok(char *s, list_t *node);
list_t *add_node(list_t **node, char *token);
void free_list(list_t *head);
int search_dir(list_t *head, char *buffer, char *s);
int _strlen(char *s);
char **command_tok(char *buffer);
int print_env(void);
char *_getpath(char *name);
void execute(char *filepath, list_t *head, char *buffer, char **command,
char *s, DIR *directory, pid_t child, int check);
int _atoi(char *s);
int exit_stat(char *buffer, list_t *head, char *s);
void free_space(list_t *head, char *s, char *buffer);
void print_error(char *buffer, int argc, char **argv);
#endif
