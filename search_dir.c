#include "shell.h"

/**
 * search_dir - this searches through the path for matching
 * directory from env variable
 *
 * @path - linked list of PATH
 *
 * Return: pointer to a matched file
 * OR -1 if fail
 * OR match not found
 */

DIR *search_dir(list_t *head, char *command)
{
	DIR *directory;
	struct dirent *dent;

	while (head->next != NULL)
	{
		directory = opendir(head->str);
		while ((dent = readdir(directory)) != NULL)
		{
			if ((_strcmp(dent->d_name, ".") == 1)
			|| (_strcmp(dent->d_name, "..") == 1))
			{
				printf("continue\n");
				continue;
			}
			if (_strcmp(command, dent->d_name) == 1)
			{
				printf("found: ");
				/**closedir(directory);*/
				return (directory);
			}
			printf("dirent: %s\n", dent->d_name);
		}
		closedir(directory);
		head = head->next;
	}
	printf("not found");
	return (NULL);
}
