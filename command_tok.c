#include "shell.h"

/**
 * command_tok - tokenizes commands from getline
 *
 * @buffer: input from getline
 *
 * Return: double pointer to array commands from buffer
 */

char **command_tok(char *buffer)
{
	int i = 0;
	int argcount = 0;
	char **command;

	for (; buffer[i]; i++)
	{
		if (buffer[i] == ' ')
			++argcount;
	}
	++argcount;

	command = malloc(sizeof(char *) * (argcount + 1));

	command[0] = strtok(buffer, " ");
	for (i = 1; i < argcount; i++)
		command[i] = strtok(NULL, " ");
	command[i] = NULL;

	return (command);
}
