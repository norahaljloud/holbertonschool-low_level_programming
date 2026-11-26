#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	size_t total;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		if (close(fd_from) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
			exit(100);
		}
		exit(99);
	}

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		total = 0;
		while (total < (size_t)r)
		{
			w = write(fd_to, buffer + total, r - total);
			if (w <= 0)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				if (close(fd_from) == -1)
				{
					dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
						fd_from);
					exit(100);
				}
				if (close(fd_to) == -1)
				{
					dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
						fd_to);
					exit(100);
				}
				exit(99);
			}
			total += w;
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		if (close(fd_from) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
			exit(100);
		}
		if (close(fd_to) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
			exit(100);
		}
		exit(98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
