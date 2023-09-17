#include"shell.h"

char *_strtok(char *str, const char *delim)
{
	char *end = NULL;
	char *token;
	token = end;
	
	if (token == end)
	{
		return end;
	}
	if (str != end)
	{
		token = str;
	}
	char *strsplit = end;
	if (_strlen(delim) == 1)
	{
		strsplit = _strchr(token, delim[0]);
	}
	else
	{
		for (size_t i = 0; i < _strlen(delim); i++)
		{
			strsplit = _strchr(token, delim[i]);
			if (strsplit != end)
			{
				break;
			}
		}
	}
	if (strsplit != end)
	{
		size_t token_l = strsplit - token;
		char* result = (char*)malloc((token_l + 1) * sizeof(char));
		for (size_t i = 0; i < token_l; i++)
		{
			result[i] = token[i];
		}
		result[token_l] = '\0';
		token = strsplit + 1;
		free(result);
		return result;
	}
}
