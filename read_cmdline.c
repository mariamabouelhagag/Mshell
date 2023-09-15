#include "shell.h"


char* cmd_read(char* cmd, size_t n, ssize_t value)
{
	cmd = NULL;
	n = 0;
	value = getline(&cmd, &n, stdin);
	if (value == -1)
	{
		free(cmd);
		perror("readline");
		exit(EXIT_FAILURE);
	}
	else
	{
		size_t i = 0;
		while (cmd[i])
		{
			if (cmd[i] == '\n')
			{
				cmd[i] = '\0';
			}
			i++;
		}
	}
	return cmd;
}
