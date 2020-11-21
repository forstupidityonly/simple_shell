#include "shell.h"

/**
 * free_space - frees for betty in main
 *
 * @buffer: buffer
 * @s: buffer
 * @head: head of list
 *
 * Return: void
 */

void free_space(list_t *head, char *s, char *buffer)
{
	free_list(head);
	free(s);
	free(buffer);
}
