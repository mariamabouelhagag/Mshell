#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <wait.h>
#include <dirent.h>
#include <stdbool.h>

size_t _strlen(const char* str);
char* cmd_read(char* cmd, size_t n, ssize_t value);
char* _strcpy(char* cpy, const char* orignal);
char** split_cmd(char* cmd, size_t n);
char* _strcat(char* dest, const char* src);
char* get_Path(const char* command);
int _strcmp(const char* str1, const char* str2);
char* find_indir(const char* command, const char* directory);
bool isCommandExists(const char* command);
char* _strchr(const char* str, int ch);
char *get_command_directory(const char *command);
char* change_directory_to_command(const char *command);
char *_getenv(const char *name);
char** get_directories_in_path();
char* get_full_path_of_command(const char* command);
void execute_builtin(char **tokens);
void free_tokens(char **tokens);
int is_command_builtin(char* command);
void display_prompt();

#endif
