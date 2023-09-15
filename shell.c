#include "shell.h"

int main(void)
{
	char *cmd = NULL, *token = NULL, **tokens = NULL, *delim = " \n";
	size_t n = 0; ssize_t value = 0; int i = 0; 
	
	char *input = cmd_read(cmd, n, value);
	char *copy = malloc(_strlen(input) + 1 * sizeof (char ));
	copy = _strcpy(copy, input);
	printf("%s \n", input);
	i = _strlen(input);
	printf("%d \n", i);
	printf("%s \n", copy);
	tokens = split_cmd(cmd, n);
	int num = 0;
	while (tokens != NULL)
	{
		printf("%s \n", tokens[num]);
		num ++ ;
	}
	for (int j = 0; j < num; j++)
	{
		free(tokens[j]);
	}
	free(tokens);
	free(copy);
}
