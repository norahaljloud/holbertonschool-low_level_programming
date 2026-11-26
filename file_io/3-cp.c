#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to close
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * write_buffer - writes the entire buffer to a file
 * @fd: destination file descriptor
 * @buffer: buffer containing data
 * @size: number of bytes to write
 * @filename: destination filename
 *
 * Return: 0 on success, 99 on failure
 */
int write_buffer(int fd, char *buffer, ssize_t size, char *filename)
{
	ssize_t written;
	size_t total;

	total = 0;
	while (total < (size_t)size)
	{
		written = write(fd, buffer + total, size - total);
		if (written <= 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
				filename);
			return (99);
		}
		total += written;
	}
	return (0);
}

/**
 * copy_data - copies data between two file descriptors
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source filename
 * @file_to: destination filename
 *
 * Return: 0 on success, 98 on read failure, 99 on write failure
 */
int copy_data(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t r;
	int status;

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		status = write_buffer(fd_to, buffer, r, file_to);
		if (status != 0)
			return (status);
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
			file_from);
		return (98);
	}
	return (0);
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, status;

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
		close_file(fd_from);
		exit(99);
	}
	status = copy_data(fd_from, fd_to, argv[1], argv[2]);
	close_file(fd_from);
	close_file(fd_to);
	if (status != 0)
		exit(status);
	return (0);
}
