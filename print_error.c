#include "shell.h"

/**
 * print_error - prints formatted errors to
 * standard error
 *
 * @command:
 *
 * Return: void
 */

void print_error(char *buffer, int argc, char **argv)
{
	int i = 0;
	printf("argc: %i\n", argc);
	write(2, argv[0], sizeof(argv[0]));

	strtok(buffer, " ");
	i = 0;
	while (buffer[i])
		i++;
	write(2, ":", 1);
	write(2, buffer, i);
	write(2, ": not found\n", 12);
}
