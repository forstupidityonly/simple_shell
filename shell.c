#include "shell.h"
/**
  * uhhhg
  */
int  main(void)
{
	char *buffer = NULL;
	ssize_t chars;
	size_t bufsize = 0;
	char *s;

	s = _getenv("PATH");
	printf("prompt$ ");
	while ((chars = getline(&buffer, &bufsize, stdin)))
	{
		if (chars == EOF)
		{
			printf("EOF");
			return (0);
		}
		printf("%s\n", s);
		printf("%s\n", buffer);
		buffer = NULL;
		bufsize = 0;
	}
	return (0);
}

