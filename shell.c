#include "shell.h"

/**
 * main - runs a simple shell
 *
 * Return: 0 when terminated
 */

int main(int argc, char **argv)
{
	char *buffer = NULL, *ext = "exit", *env = "env", *s;
	ssize_t chars;
	size_t bufsize = 1024;
	list_t *head, *node = NULL;
	argc = 1;

	head = node;
	s = _getpath("PATH");
	head = path_tok(s, node);
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "prompt$ ", 8);
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == 1)
			continue;
		else if (chars > 1)
			buffer[chars - 1] = '\0';
		if (chars == EOF)
		{
			break;
		}
		else if (_strcmp_exact(buffer, ext) == 0)
			break;
		else if (_strcmp(buffer, ext) == 1)
		{
			exit_stat(buffer, head, s);
			print_error(buffer, argc, argv);
			continue;
		}
		else if (_strcmp_exact(buffer, env) == 0)
			print_env();
		else
			search_dir(head, buffer, s, argc, argv);
		free(buffer);
		bufsize = 0;
		argc += 1;
	}
	free_space(head, s, buffer);
	return (0);
}
