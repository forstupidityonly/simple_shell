#include "shell.h"

/**
 * print_env - prints the environ variable to stdout
 *
 * Return: void
 */

int print_env(void)
{
	unsigned int i = 0, j = 0;

	while (environ[i])
	{
		j = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
	return (0);
}
