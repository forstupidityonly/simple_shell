#include "shell.h"

/**
 * path_tok - tokenizes the PATH variable
 * into a singly linked list.
 *
 * @path: char pointer to PATH as a character string
 * @head: head of a new singly linked list
 *
 * Return: head of list with PATH tokenized
 */

list_t *path_tok(char *path, list_t *head)
{
	char *token;
	printf("path = %s\n", path);
	token = strtok(path, ":");
	add_node(&head, token);

	while (token != NULL)
	{
		token = strtok(NULL, ":");
		add_node(&head, token);
	}

	return (head);
}
