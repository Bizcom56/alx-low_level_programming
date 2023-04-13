#include "main.h"

/**
 * create_file - creates a file with the given filename and writes the given
 * text content to it.
 *
 * @filename: the name of the file to create.
 * @text_content: the text content to write to the file.
 *
 * Return: 1 on success, or -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int text_length;
	int bytes_written;

	/* Check if filename is NULL */
	if (!filename)
		return (-1);

	/* Create the file with the given filename and open it for writing */
	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	/* Check if file could not be created */
	if (file_descriptor == -1)
		return (-1);

	/* If text_content is NULL, set it to an empty string */
	if (!text_content)
		text_content = "";

	/* Get the length of the text content */
	for
	(text_length = 0;
	text_content[text_length];
	text_length++);

	/* Write the text content to the file */
	bytes_written = write(file_descriptor, text_content, text_length);

	/* Check if there was an error while writing to the file */
	if (bytes_written == -1)
		return (-1);

	/* Close the file */
	close(file_descriptor);

	return (1);
}

