#include <stdio.h>
#include <string.h> // Added for strcspn function
#include <stdlib.h> // Added for system function

#define MAX_COMMAND_LENGTH 70 // Corrected macro definition

/**
 * main - Main entry point
 * Return: Return 0 upon success
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	printf("Simple Shell\n");
	printf("Enter a command: ");
	fgets(command, MAX_COMMAND_LENGTH, stdin);

	/* Remove trailing newline */
	command[strcspn(command, "\n")] = '\0';

	/* Execute command */
	system(command); // Corrected variable name

	return (0);
}
