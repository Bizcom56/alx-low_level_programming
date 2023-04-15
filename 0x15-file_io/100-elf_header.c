#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr: Prints the entry point address of an ELF file.
 *
 * This function takes a pointer to the ELF (Executable and Linkable Format)
 * header and prints the entry point address of the corresponding file.
 *
 * @ptr: Pointer to the ELF header.
 *
 * Return: void.
 */
void print_addr(char *ptr)
{
	int i;
	int begin;
	char sys;

	printf("  Entry point address:               0x");

	sys = ptr[4] + '0';
	if (sys == '1')
	{
		begin = 20;
		printf("60");
		for (i = begin; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (sys == '2')
	{
		begin = 26;
		for (i = begin; i > 23; i--)
		{
			if (ptr[i] >= 0)
				printf("%02x", ptr[i]);

			else if (ptr[i] < 0)
				printf("%02x", 256 + ptr[i]);

		}
	}
	printf("\n");
}

/**
 * print_type - prints ELF file type
 * @ptr: pointer to the ELF header
 * Return: no return value
 */
void print_type(char *ptr)
{
	char type = ptr[16];

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/*
 * Function: print_osabi
 * ---------------------
 * Prints the operating system application binary interface (osabi) indicated
 * by the given magic pointer.
 *
 * ptr: a pointer to a magic value indicating the osabi.
 *
 * Returns: nothing.
 */
void print_osabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_version: Prints the version.
 *
 * This function takes a pointer to a magic value and assumes that the
 * version is located at a specific offset from the magic value. It then
 * prints the version to stdout.
 *
 * @ptr: Pointer to the magic value.
 *
 * Return: void.
 */
void print_version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * print_data: Prints the data.
 *
 * This function takes a pointer to a magic value and assumes that the
 * data is located at a specific offset from the magic value. It then
 * prints the data to stdout.
 *
 * @ptr: Pointer to the magic value.
 *
 * Return: void.
 */
void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic: Prints information about the magic value.
 *
 * This function takes a pointer to a magic value and prints information
 * about the value, such as its format or type, to stdout.
 *
 * @ptr: Pointer to the magic value.
 *
 * Return: void.
 */
void print_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_sys: Checks the version of the system.
 *
 * This function takes a pointer to a magic value and uses it to determine
 * the version of the system. The specific implementation of this function
 * may depend on the type of magic value being used and the system being
 * checked.
 *
 * @ptr: Pointer to the magic value.
 *
 * Return: void.
 */
void check_sys(char *ptr)
{
	char sys = ptr[4] + '0';

	if (sys == '0')
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * check_elf: Checks if the given file is an ELF file.
 *
 * This function takes a pointer to a magic value and uses it to determine
 * if the corresponding file is an ELF (Executable and Linkable Format) file.
 *
 * @ptr: Pointer to the magic value.
 *
 * Return: 1 if the file is an ELF file, 0 otherwise.
 */
int check_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - Entry point of the program.
 *
 * This function checks the code for ALX SE tasks. It takes
 * the number of command-line arguments and the arguments vector as inputs,
 * although these are not used in the current implementation. The function
 * always returns 0.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int fd, ret_read;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	ret_read = read(fd, ptr, 27);

	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_sys(ptr);
	close(fd);

	return (0);
}
