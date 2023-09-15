#include "shell.h"

char* _strcpy(char* cpy, const char* orignal) 
{
	int i = 0;
	char* cpy_ptr = cpy;
	const char* orignal_ptr = orignal;
	while ((*cpy_ptr++ = *orignal_ptr++) != '\0')
	{
		cpy[i] = orignal[i];
		i++;
	}
	return (cpy);
}
