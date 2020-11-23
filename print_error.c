#include "shell.h"

/**
 * print_error - prints formatted errors to
 * standard error
 *
 * @buffer: input from getline
 * @argc: loop count
 * @argv: ./hsh
 * Return: void
 */

void print_error(char *buffer, int argc, char **argv)
{
	int i = 0;

	write(2, argv[0], _strlen(argv[0]));
	write(2, ": ", 2);
	_itoa(argc);
	strtok(buffer, " ");
	i = 0;
	while (buffer[i])
		i++;
	write(2, ": ", 2);
	write(2, buffer, i);
	write(2, ": not found\n", 12);
}
