#include "shell.h"

/**
 * main - runs a simple shell
 *
 * Return: 0 when terminated
 */

int main(void)
{
	char *buffer = NULL;
	ssize_t chars;
	size_t bufsize = 0;
	char *s;
	list_t *head;
	list_t *node = NULL;

	head = node;
	s = _getenv("PATH");
	head = path_tok(s, node);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "prompt$ ", 8);
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == EOF)
		{
			write(1, "EOF\n", 4);
			free_list(head);
			free(buffer);
			return (0);
		}
		search_dir(head, buffer);
		free(buffer);
		bufsize = 0;
	}
	free_list(head);
	free(buffer);
	return (0);
}
