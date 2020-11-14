#include "shell.h"

/**
 *
 *
 */

list_t *path_tok(char *path, list_t *head)
{
	char *token;
	printf("path = %s\n", path);
	token = strtok(path, ":");
	add_node(&head, token);

	while (token != NULL)
	{
		printf("token: %s\n", token);
		token = strtok(NULL, ":");
		add_node(&head, token);
		printf("head = %s\n", head->str);
	}

	return (head);
}
