#include "shell.h"


bool isCommandExists(const char* command)
{
	if (access(command, X_OK) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
