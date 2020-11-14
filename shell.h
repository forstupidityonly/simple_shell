#define SHELL_H

/*____ HEADERS ____*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

/*____ STRUCTURES _____*/

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
char *_getenv(char *name);
size_t print_list(const list_t *h);
list_t *path_tok(char *path, list_t *head);
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *head);

#endif
