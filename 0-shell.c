#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> /* Added for STDOUT_FILENO, STDIN_FILENO, and read function*/

#define MAX_COMMAND_LENGTH 100

/**
 * main - Main entry point
 * Return: Return 0 upon success
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char prompt[] = "simple shell\nEnter a command: ";
	ssize_t bytes_read;

	/* Write prompt to stdout */
	write(STDOUT_FILENO, prompt, strlen(prompt));
	/* Read input from stdin */

	bytes_read = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
	if (bytes_read == -1)
	{
		perror("Error reading input");
		return (EXIT_FAILURE);
	}

	/* Remove trailing newline */
	command[strcspn(command, "\n")] = '\0';

	/* Execute command */
	system(command);

	return (0);
}

