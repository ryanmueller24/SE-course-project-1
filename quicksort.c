// Quicksort function example program.
// William Wojtyska

#include <stdio.h>
#include <stdlib.h>

// Partitioning helper function.
int func_partition(int getArray[], int index_head, int index_tail) {
	int pivot = getArray[index_tail];
	int index_greater = index_head - 1;
	int temp_value = 0;

	for (int index_compared = index_head; index_compared < index_tail; index_compared++) {
		if (getArray[index_compared] <= pivot) {
			index_greater++;
			temp_value = getArray[index_compared];
			getArray[index_compared] = getArray[index_greater];
			getArray[index_greater] = temp_value;
		}
	}

	temp_value = getArray[index_greater + 1];
	getArray[index_greater + 1] = getArray[index_tail];
	getArray[index_tail] = temp_value;

	return index_greater + 1;
}

// Quicksort function.
void quicksort(int getArray[], int index_head, int index_tail) {
	int index_pivot;

	if (index_head < index_tail) {
		index_pivot = func_partition(getArray, index_head, index_tail);
		quicksort(getArray, index_head, index_pivot - 1);
		quicksort(getArray, index_pivot, index_tail);
	}
}

// Main body for testing purposes.
int main() {
	int example_a[6] = {10, 9, 2, 4, 8, 3};
	int example_b[12] = {22, 99, 34, 2, 0, 12, 30, 68, 29, 50, 42, 11};
	int len_a = sizeof(example_a) / sizeof(example_a[0]);
	int len_b = sizeof(example_b) / sizeof(example_b[0]);
	
	quicksort(example_a, 0, len_a - 1);
	for (int i = 0; i < len_a; i++) {
		printf("%d, ", example_a[i]);
	}
	printf("\n");

	quicksort(example_b, 0, len_b - 1);
	for (int i = 0; i < len_b; i++) {
		printf("%d, ", example_b[i]);
	}
	
	return 0;
}
