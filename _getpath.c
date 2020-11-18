#include "shell.h"

/**
 * _getpath - cycles through the environ variable and duplicates the PATH
 *
 * @name: const string of "PATH"
 *
 * Return: character pointer to duplicated PATH variable
 */

char *_getpath(char *name)
{
	char *path_cpy = NULL;
	unsigned int i = 0, j;

	while (environ[i])
	{
		for (j = 0; environ[i][j]; j++)
		{
			if (environ[i][j] == name[j])
				continue;
			else if (name[j] == '\0')
			{
				path_cpy = _strdup(environ[i]);
				return (path_cpy);
			}
			else
				break;
		}
		i++;
	}
	free(path_cpy);
	return (NULL);
}
