#include "file_lib.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Read the file from the command-line.
 * Usage:
 * ./a.out FILE_TO_READ FILE_TO_WRITE
 *
 */

int main(int argc, char** argv){
	// handle args
	if (argc != 3) {
		printf("invalid number of arguments: expected 2, found %d\n", argc - 1);
		return 1;
	}

	// Read the original file.
	char** fc_buffer = malloc(sizeof(char**));
	size_t byte_count = load_file(argv[1], fc_buffer);

	// determine line count
	/* int lines = 0; */
	/* for (int i = 0; i < byte_count; ++i) { */
		/* printf("reading '%c' (%d)\n", *(*fc_buffer + i), *(*fc_buffer + i)); */
		/* if (*(*fc_buffer + i) == '\n') { */
			/* ++lines; */
		/* } */
	/* } */

	free(*fc_buffer);

	/* char** fc_lines; */
	/* *fc_lines = malloc(sizeof(char*)); */
	/* fc_lines[0] = malloc(sizeof(char*)); */

	// Sort the file with the function you wrote.
	/* sort(fc_buffer, lines); */

	// Write out the new file.
	/* save_file(argv[2], *fc_buffer, byte_count); */

	// free memory
	/* free(*fc_buffer); */
	/* free(fc_lines); */
}

// You can see if your file worked correctly by using the
// command:
//
// diff ORIGINAL_FILE NEW_FILE
//
// If the command returns ANYTHING the files are different.
