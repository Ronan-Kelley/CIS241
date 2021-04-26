#include <stdio.h>
#include <stdlib.h>
#include "sorter.h"

int main(int argv, char** argc) {
	char* words[] = {
			"accentuation's",
			"toward",
			"dramatics's",
			"Molnar's",
			"carbohydrate's",
			"presidential",
			"griddles",
			"town",
			"mongrels",
			"livestock"
		};

	char* sorted_words[] = {
				"accentuation's",
				"carbohydrate's",
				"dramatics's",
				"griddles",
				"livestock",
				"Molnar's",
				"mongrels",
				"presidential",
				"toward",
				"town"
	};

	sort(words, sizeof(words) / sizeof(char*));

	for (int i = 0; i < sizeof(words) / sizeof(char*); ++i) {
		printf("words[%d] == sorted_words[%d]: %s\n", i, i, words[i] == sorted_words[i] ? "true" : "false");
	}
}
