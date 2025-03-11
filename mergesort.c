// Mergesort function example program.
// William Wojtyska

#include <stdio.h>
#include <stdlib.h>

// Merge helper function.
void merge(int getArray[], int index_head, int index_midpoint, int index_tail) {
	const int len_left = index_midpoint - index_head + 1;
	const int len_right = index_tail - index_midpoint;
	int partition_left[128];
	int partition_right[128];

	for (int i = 0; i < len_left; i++) {
		partition_left[i] = getArray[index_head + i];
	}
	for (int i = 0; i < len_right; i++) {
		partition_right[i] = getArray[index_midpoint + 1 + i];
	}

	int iterator_left = 0;
	int iterator_right = 0;
	int iterator_current = index_head;

	while (iterator_left < len_left && iterator_right < len_right) {
		if (partition_left[iterator_left] <= partition_right[iterator_right]) {
			getArray[iterator_current] = partition_left[iterator_left];
			iterator_left++;
		}
		else {
			getArray[iterator_current] = partition_right[iterator_right];
			iterator_right++;
		}
		iterator_current++;
	}

	while (iterator_left < len_left) {
		getArray[iterator_current] = partition_left[iterator_left];
		iterator_current++; iterator_left++;
	}
	while (iterator_right < len_right) {
		getArray[iterator_current] = partition_right[iterator_right];
		iterator_current++; iterator_right++;
	}
}

// Mergesort function.
void mergesort (int getArray[], int index_head, int index_tail) {
	if (index_head < index_tail) {
		int midpoint = index_head + (index_tail - index_head) / 2;
		mergesort(getArray, index_head, midpoint);
		mergesort(getArray, midpoint + 1, index_tail);
		merge(getArray, index_head, midpoint, index_tail);
	}
}

// Main body for testing purposes.
int main () {
	int example_a[6] = {10, 9, 2, 4, 8, 3};
	int example_b[12] = {22, 99, 34, 2, 0, 12, 30, 68, 29, 50, 42, 11};
	int len_a = sizeof(example_a) / sizeof(example_a[0]);
	int len_b = sizeof(example_b) / sizeof(example_b[0]);

	mergesort(example_a, 0, len_a - 1);
	for (int i = 0; i < len_a; i++) {
		printf("%d, ", example_a[i]);
	}

	mergesort(example_b, 0, len_b - 1);
	for (int i = 0; i < len_b; i++) {
		printf("%d, ", example_b[i]);
	}

	return 0;
}
