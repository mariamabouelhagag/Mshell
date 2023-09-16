#include "shell.h"

char *_getenv(const char *name)
{
	extern char **environ;
	int i, a;
	char *value;
	
	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		a = 0;
		if (name[a] == environ[i][a])
		{
			while (name[a])
			{
				if (name[a] != environ[i][a])
					break;
				a++;
			}
			if (name[a] == '\0')
			{
				value = (environ[i] + a + 1);
				return (value);
			}
		}
	}
	return (0);
}
