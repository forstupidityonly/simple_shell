#include "shell.h"

/**
  * add_node - adds node to head
  * @head: head
  * @str: str
  * Return: new node
  */

list_t *add_node(list_t **head, const char *str)
{
	int i = 0;
	list_t *duplicate;

	if (!(head && str))
		return (NULL);
	duplicate = malloc(sizeof(list_t));
	if (!duplicate)
		return (NULL);
	while (str[i])
		i++;
	duplicate->str = strdup(str);
	if (!(duplicate->str))
	{
		free(duplicate);
		return (NULL);
	}
	duplicate->len = i;
	duplicate->next = *head;
	*head = duplicate;
	return (duplicate);
}
