#include "shell.h"

char** split_cmd(char* cmd, size_t n)
{
	char* line, *line_copy, *token, **tokens;
	char* delim = " \n";
	ssize_t value = 0;
	int num_tokens = 0, i = 0;
	
	line = cmd_read(cmd, n, value);
	line_copy = malloc((_strlen(line) + 1) * sizeof(char));
	line_copy = _strcpy(line_copy, line);
	token = strtok(line_copy, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
		tokens = malloc((num_tokens + 1) * sizeof(char*));
		if (tokens == NULL)
		{
			perror("allocation error\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(line_copy, delim);
		while (token != NULL)
		{
			tokens[i] = malloc((_strlen(token) + 1) * sizeof(char));
			_strcpy(tokens[i], token);
			i++;
			token = strtok(NULL, delim);
		}
		tokens[i] = NULL;
		free(line);
		free(line_copy);
		return tokens;
}
