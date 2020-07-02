#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

int main (int argc, char* argv[]) {
	if (argc == 1) {
		printf("Not executing counter. At least 1 argument expected.\n");
		printf("Usage: ./exec number\n");
	}
	else if (argc > 1) {
		for (int index = 1; index < argc; index++) {
			int count_to = atoi(argv[index]);
			if (count_to > 0) {
				printf("Using %s.\n", argv[index]);
				counter(count_to);	
			}
			else {
				printf("Argument must be a valid number greater than 0 but got \"%s\" instead.\n", argv[index]);	
			}
		}
	}
	printf("Done!\n");
	return 0;
}
