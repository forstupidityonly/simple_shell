#include "shell.h"

/**
 * free_list - frees the memory used to create a list
 *
 * @head: first node of the list
 *
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *new;

	if (!head)
		return;
	while (head)
	{
		new = head;
		head = head->next;
		if (new->str != NULL)
			free(new->str);
		free(new);
	}
}

