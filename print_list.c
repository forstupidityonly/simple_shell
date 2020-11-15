#include "shell.h"

/**
 * print_list - print single linked list
 *
 * @h: head of list
 *
 * Return: number of elements
 */

size_t print_list(const list_t *h)
{
	size_t elements = 0;

	if (!h)
		return (0);
	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		elements += 1;
		h = h->next;
	}
	return (elements);
}
