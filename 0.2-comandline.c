#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * main - Simple shell entry point
 * Return: Always 0
 */
int main(void)
{
	char *args[MAX_ARGUMENTS];
	char line[MAX_COMMAND_LENGTH];
	ssize_t read_bytes;
	size_t len = 0;
	int status;

	while (1)
	{
		printf("$ ");
		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
		{
			perror("Error reading command");
			continue;
		}
		line[strcspn(line, "\n")] = '\0';

		char *token = strtok(line, " ");

		int arg_count = 0;

		while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
		{
			args[arg_count] = token;
			token = strtok(NULL, " ");
			arg_count++;
		}
		args[arg_count] = NULL;
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			continue;
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error executing command");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

