#include "shell.h"
char* get_full_path_of_command(const char* command)
{
	struct stat file_stat;
	const char* path = _getenv("PATH");
	char* path_copy = malloc(_strlen(path) + 1);
	_strcpy(path_copy, path);
	char* dir = strtok(path_copy, ":");
	
	while (dir != NULL)
	{
		size_t dir_len = _strlen(dir);
		size_t command_len = _strlen(command);
		char *path = malloc(dir_len + 1 + command_len + 1);
		if (full_path == NULL)
		{
			perror("Memory allocation");
			free(path_copy);
			return NULL;
		}
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		
		
		if (stat(full_path, &file_stat) == 0 && file_stat.st_mode & S_IXUSR)
		{
			free(path_copy);
			return full_path;
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
