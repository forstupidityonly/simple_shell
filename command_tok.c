#include "shell.h"

/**
 * command_tok -
 *
 * @buffer:
 *
 * Return: double pointer
 */

char **command_tok(char *buffer)
{
	int i = 0;
	int argcount = 0;
	char **command;

	strtok(buffer, "\n");

	for (; buffer[i]; i++)
	{
		if (buffer[i] == ' ')
			++argcount;
	}

	command = malloc((sizeof(char *) * argcount) + 1);

	command[0] = strtok(buffer, " ");
	for (i = 1; i < argcount; i++)
		command[i] = strtok(NULL, " ");
	command[i] = NULL;

	return (command);
}