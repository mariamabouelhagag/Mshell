#include "shell.h"

int _unsetenv(const char *cm)
{
	int a = 0, i = 0;
	if (cm == NULL || cm[0] == '\0' || _strchr(cm, '=') != NULL)
	{
		return -1;
	}
	size_t len = _strlen(cm);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], cm) == 0 && environ[i][len] == '=')
		{
			for (a = i; environ[a] != NULL; a++)
			{
				environ[a] = environ[a + 1];
			}
			break;
		}
	}
	return 0;
}
void _setenv(const char *cm, const char *value)
{
	size_t cm_len = _strlen(cm);
	size_t value_len = _strlen(value);
	char *env_var = malloc(cm_len + value_len + 2);
	
	_strcpy(env_var, cm);
	env_var[cm_len] = '=';
	_strcpy(env_var + cm_len + 1, value);
	
	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strcmp(environ[i], cm) == 0 && environ[i][cm_len] == '=')
		{
			environ[i] = env_var;
			break;
		}
	}
	if (environ[i] == NULL)
	{
		environ[i] = env_var;
		environ[i + 1] = NULL;
	}
}
void handel_exit(char **tokens)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		exit(98);
	}
}

int handel_cd(char **tokens)
{
	int result;
	if (_strcmp(tokens[0], "cd") == 0)
	{
		result = chdir(tokens[1]);
		if (result != 0)
		{
			perror("chdir error");
		}
		else
		{
			DIR *dir;
			
			struct dirent *entry;
			dir = opendir(tokens[1]);
			if (dir == NULL)
			{
				perror("error");
				return -1;
			}
			while ((entry = readdir(dir)) != NULL)
				printf("%s\n", entry->d_name);
		}
		closedir(dir);
	}
		return result;
}

