#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 150
/**
 * main - Main entry point
 * Return: Return 0 (On Success)
 */

int main(void)
{
	ssize_t read;
	char *args[10]; /*Increase the size*/

	while (1)
	{
		printf("simple_shell> ");

		if ((read = getline(&command, &len, stdin)) == -1)
		{
			printf("\n");
			free(command); /*Free dynamically allocated memory*/
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		char *token = strtok(command, " ");
		int i = 0;

		while (token != NULL && i < 10)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp");
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

