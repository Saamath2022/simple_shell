#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 * display_prompt - Display shell prompt
 */
void display_prompt(void)
{
	printf("$ ");
}

/**
 * execute_command - Execute the given command
 * @command: The command to execute
 *
 * Return: 0 if command is "exit", else return 1
 */
int execute_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		return (0);
	}
	else
	{
		printf("Executing command: %s\n", command);
		return (1);
	}
}

/**
 * main - Main entry point
 *
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	char *command = NULL;
	ssize_t command_length = 0;
	ssize_t bytes_read;

	while (1)
	{
		display_prompt();
		bytes_read = getline(&command, &command_length, stdin);
		if (bytes_read == -1)
		{
			printf("\n");
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (!execute_command(command))
		{
			break;
		}
	}
	free(command);
	return (0);
}

