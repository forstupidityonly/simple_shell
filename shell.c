#include "shell.h"

/**
  * main - runs a shell
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
	while (1)
	{
		if(isatty(STDIN_FILENO))
			printf("prompt$ ");
		chars = getline(&buffer, &bufsize, stdin);
		if (chars == EOF)
		{
			printf("EOF\n");
			return (0);
		}
		head = path_tok(s, node);
		print_list(head);
		printf("%s\n", s);
		printf("%s\n", buffer);
		buffer = NULL;
		bufsize = 0;
	}
	return (0);
}

