#include "shell.h"

int main(void)
{
	char *cmd = NULL, **tokens = NULL, *full_path = NULL;
	size_t n = 0;
	int i = 0;
	pid_t pid;
	extern char** environ;
	
	while (1)
	{
		display_prompt();
		tokens = split_cmd(cmd, n);
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free_tokens(tokens);
			return (-1);
		}
		if (pid == 0)
		{
			if (tokens[0] != NULL)
			{
				if(_strcmp(tokens[0], "exit") == 0)
				{
					break;
				}
				
				full_path = get_full_path_of_command(tokens[0]);
				execve(full_path, tokens, environ);
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(NULL);
			if(_strcmp(tokens[0], "exit") == 0)
			{
				break;
			}
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
		}
	}
	free(cmd);
	return 0;
}
