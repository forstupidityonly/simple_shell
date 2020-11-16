#include "shell.h"

/*
 * set_filepath -
 *
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
 * search_dir - this searches through the path for matching
 * directory from env variable
 *
 * @head: linked list of PATH
 * @buffer: token from buffer to find in dir
 *
 * Return: pointer to a matched file
 * OR -1 if fail
 * OR match not found
 */

int search_dir(list_t *head, char *buffer)
{
	DIR *directory;
	struct dirent *dent;
	char *filepath;
	char **command;
	int status;
	pid_t child;

	while (head->next != NULL)
	{
		directory = opendir(head->str);
		while ((dent = readdir(directory)) != NULL)
		{
			if ((_strcmp(dent->d_name, ".") == 1)
			|| (_strcmp(dent->d_name, "..") == 1))
			{
				continue;
			}
			if (_strcmp(buffer, dent->d_name) == 1)
			{
				command = command_tok(buffer);
				filepath = set_filepath(head->str, buffer);
				printf("filepath: [%s]\n", filepath);
				child = fork();
				if (!child)
					execve((const char*)filepath, command, NULL); /* 2ND ARG ARE OPTION FLAGS or ITEMS TO ACT ON */
				else
					wait(&status);
				closedir(directory);
				free(filepath);
				free(command);
				return (1);
			}
		}
		closedir(directory);
		head = head->next;
	}
	printf("not found");
	return (-1);
}
