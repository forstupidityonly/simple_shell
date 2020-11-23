#include "shell.h"

/**
 * set_filepath - creates a char string of the full path
 * to the executable
 *
 * @path_token: strtok of path
 * @filename: buffer from getline
 *
 * Return: pointer to path char string
 */

char *set_filepath(char *path_token, char *filename)
{
	unsigned int i = 0, itr = 0;
	unsigned int pathlen = _strlen(path_token);
	unsigned int filelen = _strlen(filename);
	char *filepath = malloc(sizeof(char) * ((pathlen + filelen) + 2));

	for (; i < pathlen; i++)
		filepath[i] = path_token[i];

	filepath[i] = '/';
	i++;

	for (; itr < filelen; itr++, i++)
		filepath[i] = filename[itr];

	filepath[i] = '\0';

	return (filepath);
}

/**
 * slash_check - checks buffer if is starts with a / and then
 * treats input as full path to command
 *
 * @filepath: path to command
 * @buffer: input from user
 * @command: first input from user (argv[0])
 * @check: boolean to see if command is found
 * @child: child process identifier
 *
 * Return: 1 onc success
 * OR 0 if not found
 */

int slash_check(char *filepath, char *buffer,
char **command, int check, pid_t child)
{
	int stat;

	if (buffer[0] == '/')
	{
		filepath = buffer;
		strtok(filepath, "\n");
		command = command_tok(buffer);
		if (access(filepath, F_OK) == 0)
		{
		child = fork();
		if (!child)
			check = execve((const char *)filepath, command, environ);
		else
			wait(&stat);
		if (check == -1)
			write(1, "command not found\n", 18);
		free(command);
		return (1);
		}
	}
	free(command);
	return (0);
}
/**
  * execute - execute
  * @filepath: filepath
  * @head: head
  * @buffer: user imput
  * @command: toked command
  * @s: just s
  * @directory: the directory
  * @child: process
  * @check: a check
  * Return: no
  */
void execute(char *filepath, list_t *head, char *buffer, char **command,
char *s, DIR *directory, pid_t child, int check)
{
	int status;

	filepath = set_filepath(head->str, buffer);
	child = fork();
	if (!child)
	{
		check = execve((const char *)filepath, command, environ);
		if (check == -1)
		{
			write(2, "command not found\n", 18);
			free_list(head);
			free(s);
			free(filepath);
			free(command);
			closedir(directory);
			kill(getpid(), SIGKILL);
		}
	}
	else
		wait(&status);
	closedir(directory);
	free(filepath);
	free(command);
}
/**
 * search_dir - this searches through the path for matching
 * directory from env variable
 *
 * @head: linked list of PATH
 * @buffer: token from buffer to find in dir
 * @s: string
 * Return: pointer to a matched file
 * OR -1 if fail
 * OR match not found
 */

int search_dir(list_t *head, char *buffer, char *s)
{
	DIR *directory;
	struct dirent *dent;
	char *filepath = NULL, **command = NULL;
	int check = 0, is_slash = 0;
	pid_t child = 0;

	while (*buffer == ' ')
		++buffer;
	is_slash = slash_check(filepath, buffer, command, check, child);
	if (!is_slash)
	{
		command = command_tok(buffer);
		while (head->next != NULL)
		{
			directory = opendir(head->str);
			while ((dent = readdir(directory)) != NULL)
			{
				if ((_strcmp_exact(dent->d_name, ".") == 0)
				|| (_strcmp_exact(dent->d_name, "..") == 0))
					continue;
				if (_strcmp_exact(buffer, dent->d_name) == 0)
				{
					execute(filepath, head, buffer,
command, s, directory, child, check);
					return (1);
				}
			}
			closedir(directory);
			head = head->next;
		}
		free(command);
		write(2, "command not found\n", 18);
		return (-1);
	}
	return (0);
}
