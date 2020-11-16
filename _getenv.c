#include "shell.h"
/**
 * _getenv - retrieves the environment variable
 *
 * @name: character string, containing the name of
 * the env variable name to search for.
 *
 * Return: poninter to tokenized variable (PATH)
 */
char *_getenv(char *name)
{
	char *env_val;
	char *name_cpy;
	unsigned int i = 0, len = 0;

	while (name[len] != '\0')
		len++;
	name_cpy = malloc((sizeof(char) * len) + 1);
	if (!name_cpy)
		return (NULL);
	_strcpy(name_cpy, name, len + 1);
	env_val = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(env_val, name_cpy))
		{
			env_val = strtok(NULL, "\n");
			free(name_cpy);
			return (env_val);
		}
		++i;
		env_val = strtok(environ[i], "=");
	}
	free(name_cpy);
	return (NULL);
}
