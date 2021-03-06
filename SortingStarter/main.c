#include "file_lib.h"
#include "sorter.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Read the file from the command-line.
 * Usage:
 * ./a.out FILE_TO_READ FILE_TO_WRITE
 *
 */

#define ORGANIZE_STEP 1
#define ORGANIZE_DEBUG 0
#define SORT_STEP 1
#define SORT_DEBUG 0
#define WRITE_STEP 1

void printLineSortedBuffer(char** buffer, int lines, char endChar) {
	for (int i = 0; i < lines; ++i) {
		printf("line %d: %s%c", i, *(buffer + i), endChar);
	}
}

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
	int lines = 0;
	for (int i = 0; i < byte_count; ++i) {
		char curChar = *(*fc_buffer + i);
		/* printf("reading '%c' (%d)\n", curChar, curChar); */
		if (curChar == '\n') {
			++lines;
		}
	}

	// print all of the original read
	/* for (int i = 0; i < byte_count; ++i) { */
		/* char curChar = *(*fc_buffer + i); */
		/* printf("*(fc_buffer + %d): '%c'\n", i, curChar != '\n' ? curChar : ' '); */
	/* } */

	// flush all buffers
	fflush(NULL);

	/* char** fc_lines = malloc(sizeof(char**)); */
	char** fc_lines = malloc(sizeof(char*) * lines);
	/* fc_lines[0] = malloc(sizeof(char *)); */
	size_t curByteBuf = 0;
	size_t curLine = 0;
	size_t curByteLine = 0;
	if (ORGANIZE_STEP) {
		while (curLine < lines && curByteBuf < byte_count) {
			// get address of next character in buffer
			char* curChar = *fc_buffer + curByteBuf;
			// increment pointer that tracks current character in buffer
			++curByteBuf;

			// if character is not a newline, add it to array of words
			if (*curChar != '\n' && *curChar != '\r' && *curChar != '\f') {
				/* printf("Line: %lu, Char %lu: %c\n", curLine, curByteLine, curChar); */
				/* *(*(fc_lines + curLine) + curByteLine) = curChar; */
				*((fc_lines + curLine) + curByteLine) = curChar;
				/* printf("Line: %lu, Char %lu: %c (from array)\n", curLine, curByteLine, *(*(fc_lines + curLine) + curByteLine)); */
				++curByteLine;
			} else {
				// if character is a newline, move pointers to next line/beginning of word, and allocate memory
				// additionally, insert the newline to the end of the chunk
				*(*(fc_lines + curLine) + curByteLine) = '\0';
				/* printf("curLine: %s", *(fc_lines + curLine)); */
				curByteLine = 0;
				++curLine;
				/* *(fc_lines + curLine) = malloc(sizeof(char *)); */
			}
		}

		if (ORGANIZE_DEBUG) printLineSortedBuffer(fc_lines, lines, '\n');
	}


	// Sort the file with the function you wrote.
	if (SORT_STEP) {
		sort(fc_lines, lines);
		if (SORT_DEBUG) printLineSortedBuffer(fc_lines, lines, '\n');
	}

	// Write out the new file.
	if (WRITE_STEP) {
		char* output = malloc(byte_count + 1);
		int curByteOutput = 0;
		int j = 0;

		for (int i = 0; i < lines; ++i) {
			j = 0;
			while (fc_lines[i][j] != '\0') {
				/* printf("%d:%d = %c\n", i, j, fc_lines[i][j]); */
				output[curByteOutput] = fc_lines[i][j];
				++j;
				++curByteOutput;
			}
			output[curByteOutput] = '\n';
			++curByteOutput;
		}

		output[byte_count] = '\0';

		save_file(argv[2], output, byte_count + 1);

		free(output);
	}

	// free fc_buffer
	free(*fc_buffer);
	free(fc_buffer);

	// free fc_lines
	//for (int i = 0; i < lines; ++i) {
	//	free(fc_lines[i]);
	//}
	free(fc_lines);
}

// You can see if your file worked correctly by using the
// command:
//
// diff ORIGINAL_FILE NEW_FILE
//
// If the command returns ANYTHING the files are different.
