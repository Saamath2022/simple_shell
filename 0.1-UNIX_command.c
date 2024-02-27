#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 70

/**
 * main - Main Entery point
 * Return: Return 0 (Success) else -1 if false)
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[2];

	while (1)
	{
		printf("simple_shell> ");
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = 0;
		args[0] = command;
		args[1] = NULL;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(args[0], args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

