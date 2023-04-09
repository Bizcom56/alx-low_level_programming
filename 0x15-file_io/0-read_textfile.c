#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: name of file to read
 * @letters: number of letters to read from file
 *
 * Return: number of letters read and printed to stdout
 *         or 0 if the function fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int txt;
	ssize_t nrd, nwr;
	char *buf;

	if (filename == NULL)
		return (0);

	txt = open(filename, O_RDONLY);
	if (txt == -1)
	return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (buf == NULL)
		return (0);

	nrd = read(txt, buf, letters);
	if (nrd == -1)
	{
		free(buf);
		close(txt);
		return (0);
	}

	buf[nrd] = '\0';

	nwr = write(STDOUT_FILENO, buf, nrd);
	if (nwr == -1)
	{
		free(buf);
		close(txt);
	return (0);
	}

	free(buf);
	close(txt);

	return (nwr);
}
