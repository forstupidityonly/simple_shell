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
			free_list(head);
			free(buffer);
			return (0);
		}
		head = path_tok(s, node);
		search_dir(head, buffer);
		printf("%s\n", s);
		printf("%s\n", buffer);
		free(buffer);
		bufsize = 0;
	}
	free_list(head);
	free(buffer);
	return (0);
}
