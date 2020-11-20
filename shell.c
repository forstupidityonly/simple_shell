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
	size_t bufsize = 1024;
	char *s;
	list_t *head;
	list_t *node = NULL;
	char *exit = "exit";
	char *env = "env";

	head = node;
	s = _getpath("PATH");
	head = path_tok(s, node);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "prompt$ ", 8);
		chars = getline(&buffer, &bufsize, stdin);
		if (chars > 1)
			buffer[chars - 1] = '\0';
		if (chars == EOF)
		{
			break;
		}
		else if (_strcmp_exact(buffer, exit) == 0)
			break;
		else if (_strcmp_exact(buffer, env) == 0)
			print_env();
		else
			search_dir(head, buffer, s);
		free(buffer);
		bufsize = 0;
	}
	free_list(head);
	free(s);
	free(buffer);
	return (0);
}
