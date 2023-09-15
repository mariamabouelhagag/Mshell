#include "shell.h"

char* _strcat(char* dest, const char* src)
{
	char* ptr = dest;
	while (*ptr)
	{
		ptr++;
	}
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return dest;
}
