#include "shell.h"

/**
 *
 *
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
/*				printf("path_cpy: %s\n", path_cpy);
				strtok(path_cpy, "\n");
				strtok(path_cpy, "=");
				path_cpy= strtok(NULL, "=");
				printf("path_cpy: %s\n", path_cpy); */
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
