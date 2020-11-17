#include "shell.h"

/**
 * path_tok - tokenizes the PATH variable
 * into a singly linked list.
 *
 * @s: char pointer to PATH as a character string
 * @node: head of a new singly linked list
 *
 * Return: head of list with PATH tokenized
 */

list_t *path_tok(char *s, list_t *node)
{
	char *token;

	token = strtok(s, ":");
	add_node(&node, token);

	while (token != NULL)
	{
		token = strtok(NULL, ":");
		add_node(&node, token);
	}

	return (node);
}
