#include <stdio.h>

void counter (int count_to) {
	printf("Counting to %d\n", count_to);
	for (int count = 1; count <= count_to; count++) {
		printf("%d\n", count);
	}
}
