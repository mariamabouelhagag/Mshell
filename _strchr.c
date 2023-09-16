#include "shell.h"

char* _strchr(const char* str, int ch)
{
	char* ptr = NULL;
	
	while (*str != '\0')
	{
		if (*str == ch)
		{
			ptr = (char*)str;
			break;
		}
		str++;
	}
	return ptr;
}
