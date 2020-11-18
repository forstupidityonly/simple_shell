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
	char *exit = "exit";
	char *env = "env";

	head = node;
	s = _getenv("PATH");
	head = path_tok(s, node);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "prompt$ ", 8);
		chars = getline(&buffer, &bufsize, stdin);
		if (_strcmp(buffer, exit))
			break;
		if (_strcmp(buffer, env))
			print_env();
		if (chars == EOF)
		{
			write(1, "EOF\n", 4);
			break;
		}
		search_dir(head, buffer);
		free(buffer);
		bufsize = 0;
	}
	free_list(head);
	free(buffer);
	return (0);
}
