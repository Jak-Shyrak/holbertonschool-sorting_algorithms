#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}


void quick_sort_helper(int *array, int low, int high, size_t size) {
    if (low < high) {
        int pivot_index = lomuto_partition(array, low, high, size);

        quick_sort_helper(array, low, pivot_index - 1, size);
        quick_sort_helper(array, pivot_index + 1, high, size);
    }
}

void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    quick_sort_helper(array, 0, size - 1, size);
}