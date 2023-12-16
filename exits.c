#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// remove comments function
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

// main function
int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	int file_desc, len, exit_status = 0;

	// if there are no command line arguments
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s file...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; i++)
	{
		// open file
		file_desc = open(argv[i], O_RDONLY);
		if (file_desc == -1)
		{
			perror("open");
			exit_status = 1;
			continue;
		}

		// read file line by line
		while ((len = read(file_desc, buffer, BUFFER_SIZE - 1)) > 0)
		{
			buffer[len] = '\0';
			remove_comments(buffer);
			printf("%s\n", buffer);
		}

		if (len == -1)
		{
			perror("read");
			exit_status = 1;
		}

		// close file
		close(file_desc);
	}

	exit(exit_status);
}
