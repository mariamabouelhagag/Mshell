#include "shell.h"

char* find_indir(const char* command, const char* directory)
{
	struct dirent *de;
	DIR *dr = opendir(directory);
	if (dr == NULL)
	{
		perror("Could not open directory");
		return NULL;
	}
	while ((de = readdir(dr)) != NULL)
	{
		if (_strcmp(de->d_name, command) == 0)
		{
			closedir(dr);
			size_t commandDirectoryLength = _strlen(directory) + _strlen(command) + 2;
			char* commandDirectory = malloc(commandDirectoryLength);
			if (commandDirectory == NULL)
			{
				perror("Memory allocation failed");
				return NULL;
			}
			_strcpy(commandDirectory, directory);
			_strcat(commandDirectory, "/");
			_strcat(commandDirectory, command);
			return commandDirectory;
		}
	}
	closedir(dr);
	return NULL;
}
