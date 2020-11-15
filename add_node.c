#include "shell.h"

/**
 * add_node - adds node to a the end of
 * a singly linked list
 *
 * @node: head node
 * @token: string to be placed in new node
 *
 * Return: pointer to new node
 */

list_t *add_node(list_t **node, const char *token)
{
	int i = 0;
	list_t *duplicate;

	if (!(node && token))
		return (NULL);
	duplicate = malloc(sizeof(list_t));
	if (!duplicate)
		return (NULL);
	while (token[i])
		i++;
	duplicate->str = strdup(token);
	if (!(duplicate->str))
	{
		free(duplicate);
		return (NULL);
	}
	duplicate->len = i;
	duplicate->next = *node;
	*node = duplicate;
	return (duplicate);
}
