#include <stdio.h>
#include <stdlib.h>
/* #include <string.h> */

void swap_ptrs(char** strA, char** strB) {
	char* tmp = *strA;
	*strA = *strB;
	*strB = tmp;
}

int mycharcmp(const char charA, const char charB) {
	int valA = (int) charA;
	int valB = (int) charB;
	const int caseDif = ((int) 'a') - ((int) 'A');

	if ((valA >= 'a' && valA <= 'z') && (valB >= 'A' && valB <= 'Z')) return (valA - caseDif) - valB;
	else if ((valA >= 'A' && valA <='Z') && (valB >= 'a' && valB <= 'z')) return valA - (valB - caseDif);
	else return valA - valB;
}

int mystrcmp(const char* strA, const char* strB) {
	int i = 0;
	int val = 0;
	while (1) {
		if (strA[i] == '\n' && strB[i] == '\n') return 0;
		else if (strA[i] == '\n') return -1;
		else if (strB[i] == '\n') return 1;
		else {
			val = mycharcmp(strA[i], strB[i]);
			if (val != 0) {
				return val;
			}
		}
		++i;
	}
}


void sort(char** contents, int size) {
	unsigned int i, pvt=0;

	if (size <= 1)
		return;

	// swap a randomly selected value to the last node
	swap_ptrs(contents + ((unsigned int) rand() % size), contents + size - 1);

	// reset the pivot index to zero, then scan
	for (i=0;i<size-1;++i) {
		/* if (strcasecmp(contents[i], contents[size-1]) < 0) */
		if (mystrcmp(contents[i], contents[size-1]) < 0)
			swap_ptrs(contents+i, contents+pvt++);
	}

	// move the pivot value into its place
	swap_ptrs(contents + pvt, contents + size - 1);

	// and invoke on the subsequences. does NOT include the pivot-slot
	sort(contents, pvt++);
	sort(contents + pvt, size - pvt);
}
