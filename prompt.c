#include "shell.h"
void display_prompt()
{
	ssize_t value = 0;
	if (isatty(STDIN_FILENO))
	{
		value = write(STDOUT_FILENO, "$ ", 2);
		if (value == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
}
